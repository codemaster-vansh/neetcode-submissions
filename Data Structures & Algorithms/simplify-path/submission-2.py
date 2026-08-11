class Solution:
    def simplifyPath(self, path: str) -> str:
        l1 = path.split('/')
        l1 = l1[1:]


        stack = []
        size1_of_s = 0
        for i in l1:
            if i == '' or i == '.':
                continue
            elif i == '..':
                if size1_of_s > 0:
                    stack.pop()
                    size1_of_s -= 1
            else:
                stack.append(i)
                size1_of_s += 1
        
        s = "/".join(stack)
        print(s)
        s = '/' + s
        return s