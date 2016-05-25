class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        if len(words) == 0:
            return list()
            
        result = []
        start, numChars, numWords = 0, 0, 0
        for i in range(len(words)):
            if numChars + len(words[i]) + numWords <= maxWidth:
                numChars += len(words[i])
                numWords += 1
            else:
                result.append(self.justify(words[start:i], numChars, maxWidth))
                start = i
                numChars = len(words[i])
                numWords = 1
            if i == len(words) - 1:
                # s = ' '.join(words[start:i+1])
                # s += ' ' * (maxWidth - len(s))
                s = ' '.join(words[start:i+1]).ljust(maxWidth)
                result.append(s)
        return result
        
    def justify(self, words, nc, maxWidth):
        if len(words) == 1:
            return words[0] + ' ' * (maxWidth - len(words[0]))
        spaces = maxWidth - nc
        numPlaces = len(words)-1
        s = ''
        for i in range(len(words)-1):
            s += words[i]
            tmp = math.ceil(float(spaces) / numPlaces)
            spaces -= tmp
            numPlaces -= 1
            s += ' ' * int(tmp)
        s += words[len(words)-1]
        return s
