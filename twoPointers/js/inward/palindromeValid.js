function is_palindrome_valid(s) {
  let start = 0;
  let end = s.length - 1;

  while(start < end){
    while(start < end && !/^[a-z0-9]$/i.test(s[start])){
        start = start + 1;
    }
    while(start < end && !/^[a-z0-9]$/i.test(s[end])){
        end = end - 1;
    }

    if(s[start] !== s[end]){
        return false;
    }
    start = start + 1;
    end = end - 1;
  }
  return true;
}

const s = 'a+2c!2a';
console.log(is_palindrome_valid(s));
