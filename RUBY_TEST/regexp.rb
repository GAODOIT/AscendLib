def show_regexp(a, re)
    if a =~ re
        "#{$`}<<#{$&}>>#{$'}"
    else
        "no match"
    end
end

puts show_regexp('very interesting', /t/)
puts show_regexp('Fats Waller', /a/)
puts show_regexp('Fats Waller', /ll/)
puts show_regexp('Fats Waller', /z/)

class TaxCalculator
    def initialize(name, &block)
        @name, @block = name, block
    end

#def get_tax(amount)
#        "#@name on #{amount} = #{ @block.call(amount) }"
#    end

    def get_tax(amount)
        
        "#@name on #{amount} = #{ @block.(amount) }"
    end
end

tc = TaxCalculator.new("Sales tax") {|amt| amt*0.075 }
puts tc.get_tax(100)
puts tc.get_tax(250)
