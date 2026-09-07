// Online Javascript Editor for free
// Write, Edit and Run your Javascript code using JS Online Compiler

let arr = [5,8,3,9,6,2,10,7,-1,-4]

function twoSum(arr,k){
  const myHash = new Array(Math.max(...arr)+1).fill(0)
  let n= arr.length
  for(let i=0;i<n; i++){
    let num=k-arr[i]
    if(myHash[num]){
      console.log(arr[i],num)
    }
    myHash[arr[i]]++
  }
} 
function twoSumSorted(arr,k){
  let i=0
  let j=arr.length-1
  while(i < j){
    if(arr[i]+arr[j] === k){
      console.log(arr[i],arr[j],k)
      i++
      j++
    }
    if(arr[i]+arr[j]>k){
      j--
    }else{
      i++
    }
  }
}

function findMinMax(arr){
  let min = arr[0]
  let max = arr[0]
  for(let i=0;i<arr.length;i++){
    if(arr[i]>max){
      max=arr[i]
    }else if(arr[i]<min){
      min=arr[i]
    }
  }
  return [min,max]
}
console.log(findMinMax(arr))
