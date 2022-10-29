/* 7.6 循环嵌套
一个循环体内又包含另一个完整的循环结构，称为循环嵌套。内嵌的循环中还可以再嵌套循环，这是多层嵌套。

while循环,do...while循环和for循环之间可以互相嵌套。以下为几种嵌套方式。
    while结构中嵌套while结构
    while(表达式){
        语句
        while(表达式){
            语句
        }
    }

    do...while结构中嵌套do...while结构
    do{
        语句
        do{
            语句
        }
        while(表达式);
    }
    while(表达式);

    for结构中嵌套for结构
    for(表达式;表达式;表达式){
        语句
        for(表达式;表达式;表达式){
            语句
        }
    }

    do...while结构中嵌套while结构
    do{
        语句
        while(表达式){
            语句
        }
    }
    while(表达式)

    do...while结构中嵌套for结构
    do{
        语句
        for(表达式;表达式;表达式){
            语句
        }
    }
    while(表达式)

 */