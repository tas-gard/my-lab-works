#include <stdio.h>
#include <stdbool.h>

bool isSpace(int c) {
	return (c == ' ') || (c == '\t') || (c == '\n');
}

int main() {

	size_t counter = 0;
	char c = 0, cPrev = 0;
	bool inCommentNow = false;
    bool bracketComment = false;

	while((c = getchar()) != EOF) {
		  if(!inCommentNow) {
			// Начало комментария {
            if(c == '{') 
                inCommentNow = true, bracketComment = true, c = getchar();

            // Начало комментария (*
            else if(cPrev == '(' && c == '*') 
                inCommentNow = true, bracketComment = false, c = getchar();   
            

        } else {
            // Подсчет слов (переход от не-пробела к пробелу)
            if(isSpace(c) && !isSpace(cPrev)) 
                ++counter;
            
            // Конец комментария }
            if(bracketComment && c == '}') 
                inCommentNow = false;

            // Конец комментария *)
            else if(!bracketComment && cPrev == '*' && c == ')') 
                inCommentNow = false;
        }

		cPrev = c;
	}

	printf("Counter = %zu\n", counter);
}
