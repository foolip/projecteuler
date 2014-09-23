steps = 20

factorial n = product [1..n]

answer = div (factorial (2 * steps)) ((factorial steps) ^ 2)

main = print answer
