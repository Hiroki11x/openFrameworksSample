//
//  GUI.cpp
//  abebirthday
//
//  Created by HirokiNaganuma on 2015/09/18.
//
//
#include "GUI.h"

void GUI::setup(ofPtr<UniformInfos> uniforms)
{
    this->uniforms = uniforms;
    
    gui.setDefaultWidth(ofGetWidth() - 20);
    gui.setup(uniforms->parameters, "settings/uniforms.xml");
    gui.loadFromFile("settings/uniforms.xml");
    
    bGUIHide = false;
}

void GUI::draw()
{
    if (!bGUIHide)
    {
        gui.draw();
    }
}

void GUI::toggleVisible()
{
    bGUIHide = !bGUIHide;
}

void GUI::resetToDefault()
{
    uniforms->resetToSystemDefault();
}
