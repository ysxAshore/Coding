#include <stdio.h>
#include <string.h>
#include <malloc.h>

char res[1001];
char temp[1001];
int isPalindrome(char *s){
    int size=strlen(s);
    int sign=1;
    for (int i = 0; i < size/2; i++){
        if (s[i]!=s[size-1-i]){
            sign=0;
            break;
        }
    }
    return sign;
}

char * longestPalindrome(char * s){
    int size=strlen(s);
    memset(res,'\0',size+1);
    res[0]=s[0];
    int cur=1;
    for (int i = 0; i < size-cur; i++){
        for (int j = cur+i; j<size; j++){
            strncpy(temp,s+i,j-i+1);
            temp[j-i+1]='\0';
            if(isPalindrome(temp)){
                strncpy(res,temp,j-i+1);
                cur=j-i+1;
            }
        }
        
    }
    return res;
}
int main(){
    printf("%s",longestPalindrome("kyyrjtdplseovzwjkykrjwhxquwxsfsorjiumvxjhjmgeueafubtonhlerrgsgohfosqssmizcuqryqomsipovhhodpfyudtusjhonlqabhxfahfcjqxyckycstcqwxvicwkjeuboerkmjshfgiglceycmycadpnvoeaurqatesivajoqdilynbcihnidbizwkuaoegmytopzdmvvoewvhebqzskseeubnretjgnmyjwwgcooytfojeuzcuyhsznbcaiqpwcyusyyywqmmvqzvvceylnuwcbxybhqpvjumzomnabrjgcfaabqmiotlfojnyuolostmtacbwmwlqdfkbfikusuqtupdwdrjwqmuudbcvtpieiwteqbeyfyqejglmxofdjksqmzeugwvuniaxdrunyunnqpbnfbgqemvamaxuhjbyzqmhalrprhnindrkbopwbwsjeqrmyqipnqvjqzpjalqyfvaavyhytetllzupxjwozdfpmjhjlrnitnjgapzrakcqahaqetwllaaiadalmxgvpawqpgecojxfvcgxsbrldktufdrogkogbltcezflyctklpqrjymqzyzmtlssnavzcquytcskcnjzzrytsvawkavzboncxlhqfiofuohehaygxidxsofhmhzygklliovnwqbwwiiyarxtoihvjkdrzqsnmhdtdlpckuayhtfyirnhkrhbrwkdymjrjklonyggqnxhfvtkqxoicakzsxmgczpwhpkzcntkcwhkdkxvfnjbvjjoumczjyvdgkfukfuldolqnauvoyhoheoqvpwoisniv"));
}