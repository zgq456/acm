puts 91 * 2
limit = 2**31-1
1.upto(91).each do |i|
  puts "#{i} #{i+i}"
  puts "#{limit-i} #{limit}"
end
