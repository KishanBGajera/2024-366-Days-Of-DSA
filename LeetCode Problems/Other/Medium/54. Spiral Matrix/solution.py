from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        result = []

        state = 'right'
        no_of_elements = len(matrix[0]) * len(matrix)

        start_idx = 0
        end_idx = len(matrix[0])-1
        row_to_start = 0
        row_to_end = len(matrix)-1

        while(len(result) < no_of_elements):
            if state == 'right':
                for element in matrix[row_to_start][start_idx: end_idx+1]:
                    result.append(element)

                state = 'down'
                row_to_start += 1
                
            elif state == 'down':
                for row in matrix[row_to_start: row_to_end+1]:
                    result.append(row[end_idx])

                state = 'left'
                temp = row_to_start
                row_to_start = row_to_end
                row_to_end = temp 
                end_idx -= 1
            
            elif state == 'left':
                for i in range(end_idx, start_idx-1, -1):
                    result.append(matrix[row_to_start][i])

                state = 'up'
                row_to_start-=1

            elif state == 'up':
                for i in range(row_to_start, row_to_end-1, -1):
                    result.append(matrix[i][start_idx])

                state = 'right'
                temp = row_to_end
                row_to_end = row_to_start
                row_to_start = temp
                start_idx+=1

        return result