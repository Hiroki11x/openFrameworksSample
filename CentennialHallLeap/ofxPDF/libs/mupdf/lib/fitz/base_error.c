#include "fitz-internal.h"

/* Warning context */

void fz_var_imp(void *var)
{
	var = var; /* Do nothing */
}

void fz_flush_warnings(fz_context *ctx)
{
	if (ctx->warn->count > 1)
	{
		fprintf(stderr, "warning: ... repeated %d times ...\n", ctx->warn->count);
		LOGE("warning: ... repeated %d times ...\n", ctx->warn->count);
	}
	ctx->warn->message[0] = 0;
	ctx->warn->count = 0;
}

void fz_warn(fz_context *ctx, char *fmt, ...)
{
	va_list ap;
	char buf[sizeof ctx->warn->message];

	va_start(ap, fmt);
	vsnprintf(buf, sizeof buf, fmt, ap);
	va_end(ap);

	if (!strcmp(buf, ctx->warn->message))
	{
		ctx->warn->count++;
	}
	else
	{
		fz_flush_warnings(ctx);
		fprintf(stderr, "warning: %s\n", buf);
		LOGE("warning: %s\n", buf);
		fz_strlcpy(ctx->warn->message, buf, sizeof ctx->warn->message);
		ctx->warn->count = 1;
	}
}

/* Error context */

static void throw(fz_error_context *ex)
{
	if (ex->top >= 0) {
		fz_longjmp(ex->stack[ex->top].buffer, 1);
	} else {
		fprintf(stderr, "uncaught exception: %s\n", ex->message);
		LOGE("uncaught exception: %s\n", ex->message);
		exit(EXIT_FAILURE);
	}
}

int fz_push_try(fz_error_context *ex)
{
	assert(ex);
	ex->top++;
	/* Normal case, get out of here quick */
	if (ex->top < nelem(ex->stack)-1)
		return 1;
	/* We reserve the top slot on the exception stack purely to cope with
	 * the case when we overflow. If we DO hit this, then we 'throw'
	 * immediately - returning 0 stops the setjmp happening and takes us
	 * direct to the always/catch clauses. */
	assert(ex->top == nelem(ex->stack)-1);
	strcpy(ex->message, "exception stack overflow!\n");
	ex->stack[ex->top].code = 1;
	return 0;
}

char *fz_caught(fz_context *ctx)
{
	assert(ctx);
	assert(ctx->error);
	return ctx->error->message;
}

void fz_throw(fz_context *ctx, char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vsnprintf(ctx->error->message, sizeof ctx->error->message, fmt, args);
	va_end(args);

	fz_flush_warnings(ctx);
	fprintf(stderr, "error: %s\n", ctx->error->message);
	LOGE("error: %s\n", ctx->error->message);

	throw(ctx->error);
}

void fz_rethrow(fz_context *ctx)
{
	throw(ctx->error);
}
