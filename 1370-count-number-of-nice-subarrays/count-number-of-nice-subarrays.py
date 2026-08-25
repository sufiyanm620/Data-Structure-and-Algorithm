class Solution:
    def numberOfSubarrays(self, arr: List[int], k: int) -> int:
        def atmost(k):
            left = 0
            ans = 0 
            count = 0
            for i in range(len(arr)):
                if arr[i] % 2 == 1:
                    count += 1
                while left < len(arr) and count > k:
                    if arr[left] % 2 == 1:
                        count -= 1
                    left += 1
                ans += i - left + 1
            return ans
        return atmost(k) - atmost(k-1)


            

