catch (:done) do
    while line = gets
        throw :done if line =~ /quit/
        puts line
    end
    puts "after the while end!"
end
