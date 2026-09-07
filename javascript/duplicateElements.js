let arr = [8,3,6,4,6,6,8,2,7]

// finding duplicate in a sorlted array
function findDuplicateElementSorted(arr,n){
 let lastDuplicate = 0
  for(let i =0;i<n;i++){
    if(arr[i] === arr[i+1] && arr[i] !== lastDuplicate){
        lastDuplicate = arr[i]
        console.log(arr[i])
    }
  }
}

// function countDuplicateElement(arr,n){
//   for(let i =0; i<n;i++){
//     if(arr[i] === arr[i+1]){
//         let j = i
//       while(arr[i] === arr[j]) j++
//       console.log(j-i)
//       i=j-1
//     }
//   }
// }

// Duplicate count
function countDuplicateElement(arr,n){
  const myHash = new Array(Math.max(...arr)+1).fill(0)
  for(let i=0;i<n;i++){
    myHash[arr[i]]++
  }
  console.log(myHash)
  for(let j = 0;j<myHash.length;j++){
    if(myHash[j]>1){
      console.log(`${j} appeared ${myHash[j]} times`)
    }
  }
}
// find unsorted duplicates
function findDuplicateElement(arr,n){
  for(let i=0;i < n; i++){
    if(arr[i] !== -1){
      let j = i+1
      let count = 1
    while(j < n){
      if(arr[i] === arr[j]){
        arr[j]=-1
        count++
      }
       j++
    }
      if(count >1){
        console.log(`${arr[i]} appeared ${count} times`)
      }
    }
  }
}

findDuplicateElement(arr,arr.length)
