from typing import List
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token.isdigit() or len(token) > 1:
                stack.append(int(token))
            else:
                b = stack.pop()
                a = stack.pop()
                if token == '+':
                    a += b
                elif token == '-':
                    a -=b
                elif token == '*':
                    a *= b
                else: 
                    a /= b
                    a = int(a)
                stack.append(a)
        return stack.pop()


solution = Solution()
tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
ans = solution.evalRPN(tokens)
print(ans)

