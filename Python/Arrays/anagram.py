def anagram2(s,t):
    if len(s) != len(t):
        return False
    
    s_count = {}
    t_count = {}
    
    for i in range(len(s)):
        s_count[s[i]] = s_count.get(s[i],0) + 1
        t_count[t[i]] = t_count.get(t[i],0) + 1
    
    return s_count == t_count


def anagram1(s,t):
    if len(s) != len(t):
        return False
    
    return sorted(s) == sorted(t)

s = "tab"
t = "bat"

print(anagram1(s,t))