#!/bin/sh

perr() {
    echo "$@" >&2
    exit 1
}

if [ $# -eq 0 ]; then
    perr "usage: $0 <line_no> [slice.txt] [data.in] [data.out]"
fi

line=${1}
slice=${2:-slice.txt}
input=${3:-data.in}
output=${4:-data.out}

read i o <<< $(awk -v line=$line '
$3 <= line && line <= $4 {
  print $1","$2" "$3","$4;
}' "$slice")

sed -n "${i}p" "$input"
echo '---'
sed -n "${o}p" "$output"
