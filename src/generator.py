# template text
templateText = "$1 , hello your course is $2, $3 hours, at $4"

# generator
def generator(templateText):
    yuansu = ('$1','$2','$3','$4')
    student1 = {'$1':'Zed','$2':'c language','$3':36,'$4':'The teaching building 3'}
    for i in yuansu:
        old = str(i)
        new = str(student1[i])
        templateText = templateText.replace(old,new)
    return templateText

print generator(templateText)
