# Chaining

m = Number of slots in hash table  
n = Number of keys to be inserted in hash table  
Load factor α = n/m  
Expected time to search = O(1 + α)  
Expected time to delete = O(1 + α)  
Time to insert = O(1)  
Time complexity of search insert and delete is 
O(1) if  α is O(1)  

# Open addressing

Insert, Search operation involve probing till element inserted or found
Delete operation marks element, mark identifies element as deleted and signals possible insertion point

## Linear probing

(hash(input) + i)% HASHTABLESIZE  
Performs hash function to find index, increment index by 1 till inserted  

Primary clustering - elements cluster, insert and search increasingly linear  
Secondary clustering - same collision chain causing same sequence of probing  

## Quadratic probing

(hash(input) + i * i) % HASHTABLESIZE

## Randomizer

srand(time(NULL))  

## Double hasing

(hash(input) + i * hash(input)) % HASHTABLESIZE
