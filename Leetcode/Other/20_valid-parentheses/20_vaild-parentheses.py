# 20. 有效的括号
# Created by kaide on 2021/7/4.
pairs = {
    "}": "{",
    "]": "[",
    ")": "("
}

stak = list()


def is_valid(s: str) -> bool:
    """
    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
    :param s: 字符串
    :return: 字符串是否有效
    """
    if len(s) % 2 == 1:
        return False
    for ch in s:
        if ch in pairs:  # 是右括号，进行匹配左括号
            if not stak or stak[-1] != pairs[ch]:
                return False
            stak.pop()
        else:  # 是左括号，压入栈中
            stak.append(ch)
    return not stak


if __name__ == '__main__':
    s1 = "()[]{}"
    print(is_valid(s1))  # expect: True
    s2 = "([)]"
    print(is_valid(s2))  # expect: False
