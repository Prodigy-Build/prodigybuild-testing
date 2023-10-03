// Original file contents:

/*
    This function checks if a given number is even or odd.
    It returns true if the number is even, and false otherwise.
*/

function isEven(number) {
  if (number % 2 === 0) {
    return true;
  } else {
    return false;
  }
}

// Instructions: Write unit tests

function testIsEven() {
  // Test case 1: number is 4 (even)
  console.log(isEven(4) === true);

  // Test case 2: number is 7 (odd)
  console.log(isEven(7) === false);

  // Test case 3: number is 0 (even)
  console.log(isEven(0) === true);

  // Test case 4: number is -2 (even)
  console.log(isEven(-2) === true);

  // Test case 5: number is -3 (odd)
  console.log(isEven(-3) === false);
}

testIsEven();