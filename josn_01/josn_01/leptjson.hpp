//
//  leptjson.hpp
//  josn_01
//
//  Created by 周杰 on 2021/11/9.
//

#ifndef leptjson_hpp
#define leptjson_hpp

#include <stdio.h>
typedef enum {LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER,  LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT}lept_type;
typedef struct
{
    lept_type type;
}lept_value;
enum{
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,//json只含有空白
    LEPT_PARSE_INVALID_VALUE,//值不是null,false, true 三者之一
    LEPT_PARSE_ROOT_NOT_SINGULAR//一个值之后，在空白之后还有其他字符
};
//解析json
int lept_parse(lept_value* v, const char* json);
//访问结果的函数，获取其类型
lept_type lept_get_type(const lept_value* v);

#endif /* leptjson_hpp */
