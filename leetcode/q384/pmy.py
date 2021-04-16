from typing import List
import random

class Solution:

    def __init__(self, nums: List[int]):
        self.array = nums
        self.origin = list(nums)


    def reset(self) -> List[int]:
        self.array = self.origin
        self.origin = self.array.copy()
        return self.array


    def shuffle(self) -> List[int]:
        for i in range(len(self.array)):
            index = random.randrange(i, len(self.array))
            self.array[i], self.array[index] = self.array[index], self.array[i]
        return self.array
