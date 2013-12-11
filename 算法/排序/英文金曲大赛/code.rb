ARGF.each do |line|
  data = line.split
  value = data[0..-2].map &:to_f
  result = (value.reduce(:+) - value.minmax.reduce(:+)) / 5.0
  printf "%s %.2f\n", data[-1], result
end
