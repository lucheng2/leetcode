class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        cnt = 0
        lst = text.strip().split()
        st = set(brokenLetters)
        for i in range(len(lst)):
            for j in range(len(lst[i])):
                if st.__contains__(lst[i][j]):
                    break
            else:
                cnt += 1
        return cnt


