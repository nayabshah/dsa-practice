let arr = [1,2,3,4,5,6,8,9,12,13,14,16]
function findMissingEl_hashTable(arr,n){
  myHashTable = new Array(Math.max(...arr)+1).fill(0)
  for(let i=0;i<n;i++){
    myHashTable[arr[i]]++
  }
  for(let j = 1;j<myHashTable.length;j++){
    if(myHashTable[j]===0){
      console.log(j)
    }
  }
}

findMissingEl_hashTable(arr,arr.length)
