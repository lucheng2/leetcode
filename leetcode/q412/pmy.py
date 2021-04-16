class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ans = []
        fizz_buzz_dict = {3: 'Fizz', 5: 'Buzz'}
        for i in range(1, n + 1):
            tmp = ''
            for key in fizz_buzz_dict:
                if i % key == 0:
                    tmp += fizz_buzz_dict[key]
            if tmp == '':
                tmp = str(i)
            ans.append(tmp)
        return ans

