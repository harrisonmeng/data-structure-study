typedef struct str
{
    char *data;
    int length;
}stringtype;

void StrAssign(stringtype **s, char cstr[]);
void DestroyStr(stringtype *s);
void StrCopy(stringtype *s, stringtype *t);
int StrEqual(stringtype *s, stringtype *t);
int StrLength(stringtype *s);
stringtype* Concat(stringtype *s, stringtype *t);
stringtype* SubStr(stringtype *s, int i, int j);
stringtype* InsStr(stringtype *s1, int i, stringtype *s2);
stringtype* DelStr(stringtype *s, int i, int j);
void DisStr(stringtype *s);
stringtype* RepStr(stringtype *s, int i, int j, stringtype *t);
