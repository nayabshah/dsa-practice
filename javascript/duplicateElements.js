// finding duplicate in a sorlted array
let arr = [3,6,8,8,10,12,15,15,15,15,20]
function findDuplicateElement(arr,n){
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


// USING HASH TABLE
function countDuplicateElement(arr,n){
  const myHash = new Array(arr[n-1]).fill(0)
  for(let i=0;i<n;i++){
    myHash[arr[i]]++
  }
  for(let j = 0;j<myHash.length;j++){
    if(myHash[j]>1){
      console.log(`${j} appeared ${myHash[j]} times`)
    }
  }
}

countDuplicateElement(arr,arr.length)
