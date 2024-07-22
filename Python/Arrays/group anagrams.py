def group_anagrams(strs):
    anagram_dict = {}

    for word in strs:
        sorted_word = ''.join(sorted(word))

        if sorted_word not in anagram_dict:
            anagram_dict[sorted_word] = []
        
        anagram_dict[sorted_word].append(word)

    return list(anagram_dict.values())

strs = ["act","pots","tops","cat","stop","hat"]
print(group_anagrams(strs))