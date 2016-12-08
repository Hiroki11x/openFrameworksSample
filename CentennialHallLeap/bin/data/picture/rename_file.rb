Dir.glob("*").each_with_index do |file_name, i|
  unless file_name == __FILE__
    new_file_name = "#{i.to_s.rjust(4, "0")}.jpg"
    `mv #{file_name} #{new_file_name}`
  end
end
