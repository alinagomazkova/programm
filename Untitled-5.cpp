#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // Создаем массив высот для каждого столбца
    vector<int> heights(cols, 0);
    
    int maxArea = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Обновляем высоту текущего столбца
            if (matrix[i][j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        
        // Ищем площадь самого большого прямоугольника для текущей строки
        // с помощью стека и алгоритма "нахождения ближайшего меньшего элемента"
        stack<int> st;
        int area = 0;
        int j = 0;
        
        while (j < cols) {
            if (st.empty() || heights[j] >= heights[st.top()]) {
                st.push(j++);
            } else {
                int tp = st.top();
                st.pop();
                area = max(area, heights[tp] * (st.empty() ? j : j - st.top() - 1));
            }
        }
        
        while (!st.empty()) {
            int tp = st.top();
            st.pop();
            area = max(area, heights[tp] * (st.empty() ? j : j - st.top() - 1));
        }
        
        maxArea = max(maxArea, area);
    }
    
    return maxArea;
}

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    
    int result = maximalRectangle(matrix);
    cout << "Максимальная площадь прямоугольника: " << result << endl;
    
    return 0;
}