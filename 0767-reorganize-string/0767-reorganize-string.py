import collections
import heapq

class Solution:
    def reorganizeString(self, s: str) -> str:
        # Step 1: Count character frequencies
        char_counts = collections.Counter(s)
        max_freq = max(char_counts.values())
        
        # Condition check: Impossible to reorganize if a character occurs too often
        if max_freq > (len(s) + 1) // 2:
            return ""
        
        # Step 2: Build a Max-Heap using negative frequencies (Python uses min-heaps)
        max_heap = [[-freq, char] for char, freq in char_counts.items()]
        heapq.heapify(max_heap)
        
        res = []
        prev_freq, prev_char = 0, ""
        
        # Step 3: Extract and interleave characters dynamically
        while max_heap:
            freq, char = heapq.heappop(max_heap)
            res.append(char)
            
            # Re-add the previous held character back to the heap if counts remain
            if prev_freq < 0:
                heapq.heappush(max_heap, [prev_freq, prev_char])
                
            # Update values to hold the current character back for one turn
            prev_freq = freq + 1  # Approaching 0 since it is a negative representation
            prev_char = char
            
        return "".join(res)
