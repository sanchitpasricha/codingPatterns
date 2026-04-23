export function next_lexicographical_sequence(s) {
  const letters = s.split('')
  // Locate the pivot, which is the first character from the right that breaks
  // non-increasing order. Start searching from the second-to-last position.
  let pivot = letters.length - 2
  while (pivot >= 0 && letters[pivot] >= letters[pivot + 1]) {
    pivot -= 1
  }

  if (pivot === -1) {
    return letters.reverse().join('')
  }

  let rightmostSuccessor = letters.length - 1
  while (letters[rightmostSuccessor] <= letters[pivot]) {
    rightmostSuccessor -= 1
  }

  ;[letters[pivot], letters[rightmostSuccessor]] = [
    letters[rightmostSuccessor],
    letters[pivot],
  ]

  const suffix = letters.splice(pivot + 1).reverse()
  return letters.concat(suffix).join('')
}

const word = 'accb';
const next_lax = next_lexicographical_sequence(word);
console.log(next_lax)