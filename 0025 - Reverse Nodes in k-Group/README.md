#### [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)

#### [Solution's post](https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/1797999/c-best-way-i-could-do-it-explained-12-26ms)

Difficulty: Hard

| Time Submitted | Runtime | Memory  |
|----------------|---------|---------|
| 02/24/2022     | 12 ms   | 13.9 MB |
| 02/24/2022     | 16 ms   | 13.7 MB |
| 02/24/2022     | 20 ms   | 12.5 MB |

#### ***I know it's not the best solution! However, it's the only way I could do it***

**I will try to explain the best way possible. Read it before downvote unú**

First of all, we need to understand what we need to do. So, we have `n` nodes in a linked list and `k` value that tell us when to split our list and reverse the values from beginning to end (of that list). 

**Example**:
List = [1, 2, 3, 4, 5, 6, 7, 8]
k = 2
-> Split every `k` steps
[1, 2] **|** [3, 4] **|** [5, 6] **|** [7, 8]
-> Reverse every split
[2, 1] **|** [4, 3] **|** [6, 5] **|** [8, 7]
-> Result
[2, 1, 4, 3, 6, 5, 8, 7]

*But what happen if there are not enough nodes in the linked list for complete the `k` step?*
Well, basically we return only that *split* as we recieved it.

**Example**:
List = [1, 2, 3, 4, 5, 6, 7, 8]
k = 3
-> Split every `k` steps
[1, 2, 3] **|** [4, 5, 6] **|** [7, 8]
-> Reverse every split
[3, 2, 1] **|** [6, 5, 4] **|** [7, 8]
-> Result
[3, 2, 1, 6, 5, 4, 7, 8]

**Note**: If we can see the 3rd split ([7, 8]), it's the same when we did the *reverse*, and the reason is because his length is not equal that `k`. 

**Well, I hope so the idea is explained.**

#### ***Now, the code continue the idea, or something like that.***

First, we need to get every split from the linked list and I used vectors to store them for two reasons: they are super easy to use and the have a lot of functions as `reverse` which allow us to flip all the vector. **E.g. 1-3 -> 3-1** 

As we know the split have a `k` length. With this in mind, we just need to store the *tmp split* in the vector, and check when the linked list is *`nullptr`* if the last tmp split have the same size as `k` because we can have an incomplete split which is necessary to add in the vector. ***Check the `kNodes` function.***

Next, we need to reverse every *subvector-list* stored in the main vector. To do that we only apply the `reverse` function. Super easy! ***Check the `getReverse` function.*** Remember that we only apply the function if the sublist size is equal to `k`! If the sublist is not they will be same as we received them, and that's idea.

After, it's necessary to merge all the sublist in one. To do it, we are gonna use another function from the vector called `insert`. This function will allow us to insert one list at the end of the current list. **E.g. \[[2, 1], [4, 3]] -> [2, 1, 4, 3]** ***Check the `mergeVectors` function.***

Finally, we will use the original linked list to reassign the values of every node using our merged list of reverse values. ***Check the `newValue` function.*** And, return the *head*.

**P.S.** I'm sorry if I can't explain it very well. It's complicated to translate it haha