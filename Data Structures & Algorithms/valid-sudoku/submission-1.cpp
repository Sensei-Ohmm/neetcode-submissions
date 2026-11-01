class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool hasNum[9];
        for( int i = 0; i < 9; i++){

            for( int j = 0; j < 9; j++){
                if(board[i][j] != '.')
                    if( !hasNum[board[i][j] - '1']){
                        hasNum[board[i][j] - '1'] = true;
                    } else {
                        cout << "Bigger";
                        return false;
                    }
            }

            for( int j = 0; j < 9; j++){
                hasNum[j] = false;
            }
        }

        for( int i = 0; i < 9; i++){

            for( int j = 0; j < 9; j++){
                if(board[j][i] != '.')
                    if( !hasNum[board[j][i] - '1']){
                        hasNum[board[j][i] - '1'] = true;
                    } else {
                        cout << "Bigger";
                        return false;
                    }
            }

            for( int j = 0; j < 9; j++){
                hasNum[j] = false;
            }
        }

        for( int n = 0; n < 9; n += 3){
            for ( int m = 0; m < 9; m += 3){
                for( int i = n; i < n+3; i++){
                    for ( int j = m; j < m+3; j++){
                        if(board[i][j] != '.')
                            if( !hasNum[board[i][j] - '1']){
                                hasNum[board[i][j] - '1'] = true;
                            } else {
                                cout << " Inner";
                                return false;
                            }
                    }
                }

                for( int j = 0; j < 9; j++){
                    hasNum[j] = false;
                }
            }
        }

        return true;
    }
};
