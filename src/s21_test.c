#include <check.h>
#include <string.h>
#include "s21_string.h"

#define size 200

START_TEST(test_s21_memchr) {
char str1[20] = "hellohello";
char str2[20] = "Hello world\n\0";
int c1 = 'e';
int c2 = 'm';
size_t n1 = 20;
size_t n2 = 5;
size_t n3 = 0;

ck_assert_ptr_eq(s21_memchr(str1, c1, n1), memchr(str1, c1, n1));
ck_assert_ptr_eq(s21_memchr(str1, c1, n2), memchr(str1, c1, n2));
ck_assert_ptr_eq(s21_memchr(str1, c2, n1), memchr(str1, c2, n1));
ck_assert_ptr_eq(s21_memchr(str2, c1, n1), memchr(str2, c1, n1));
ck_assert_ptr_eq(s21_memchr(str2, c1, n3), memchr(str2, c1, n3));
}
END_TEST

START_TEST(test_s21_memcmp) {
char str1[20] = "Hello, world";
char str2[20] = "hello, world";
char str3[20] = "Hello, world";

    ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
    ck_assert_int_eq(s21_memcmp(str1, str2, 8), memcmp(str1, str2, 8));
    ck_assert_int_eq(s21_memcmp(str1, str3, 8), memcmp(str1, str3, 8));
}
END_TEST

START_TEST(test_s21_memcpy) {
char str1[20] = "1234567890";
char str2[20] = "abcdefghi";
char str3[20] = "";
char str4[20] = " \n\0";
s21_size_t n1 = 5;
s21_size_t n2 = 0;

ck_assert_ptr_eq(s21_memcpy(str1, str3, n1), memcpy(str1, str3, n1));
ck_assert_ptr_eq(s21_memcpy(str1, str2, n1), memcpy(str1, str2, n1));
ck_assert_ptr_eq(s21_memcpy(str1, str2, n2), memcpy(str1, str2, n2));
ck_assert_ptr_eq(s21_memcpy(str1, str4, n1), memcpy(str1, str4, n1));
}
END_TEST

START_TEST(test_s21_memmove) {
char dest[50] = "1234567890";
s21_size_t n1 = 3;
s21_size_t n2 = 4;
s21_size_t n3 = 2;
s21_size_t n4 = 7;
s21_size_t n5 = 15;
s21_size_t n6 = 0;
s21_size_t n7 = 20;
s21_size_t n8 = 6;

ck_assert_ptr_eq(s21_memmove(&dest[0], &dest[5], n1), memmove(&dest[0], &dest[5], n1));
ck_assert_ptr_eq(s21_memmove(&dest[3], &dest[3], n2), memmove(&dest[3], &dest[3], n2));
ck_assert_ptr_eq(s21_memmove(&dest[6], &dest[3], n3), memmove(&dest[6], &dest[3], n3));
ck_assert_ptr_eq(s21_memmove(&dest[2], &dest[8], n4), memmove(&dest[2], &dest[8], n4));
ck_assert_ptr_eq(s21_memmove(&dest[8], &dest[2], n4), memmove(&dest[8], &dest[2], n4));
ck_assert_ptr_eq(s21_memmove(&dest[0], &dest[0], n5), memmove(&dest[0], &dest[0], n5));
ck_assert_ptr_eq(s21_memmove(&dest[7], &dest[3], n6), memmove(&dest[7], &dest[3], n6));
ck_assert_ptr_eq(s21_memmove(&dest[7], &dest[3], n7), memmove(&dest[7], &dest[3], n7));
ck_assert_ptr_eq(s21_memmove(&dest[3], &dest[1], n8), memmove(&dest[3], &dest[1], n8));
}
END_TEST

START_TEST(test_s21_memset) {
char str1[50] = "123";
char str2[50] = "";
int c1 = 1;
int c2 = '\n';
s21_size_t n1 = 2;
s21_size_t n2 = 5;
s21_size_t n3 = 0;

ck_assert_ptr_eq(s21_memset(str1, c1, n1), memset(str1, c1, n1));
ck_assert_ptr_eq(s21_memset(str1, c1, n2), memset(str1, c1, n2));
ck_assert_ptr_eq(s21_memset(str1, c1, n3), memset(str1, c1, n3));
ck_assert_ptr_eq(s21_memset(str2, c2, n2), memset(str2, c2, n2));
}
END_TEST

START_TEST(test_s21_strcat) {
char str1[50] = "123";
char str2[50] = "Hello world\n\0";
char str3[50] = "a\n\0";
char str4[50] = " \n\0";
char str5[50] = " \0";

ck_assert_ptr_eq(s21_strcat(str1, str2), strcat(str1, str2));
ck_assert_ptr_eq(s21_strcat(str2, str3), strcat(str2, str3));
ck_assert_ptr_eq(s21_strcat(str3, str4), strcat(str3, str4));
ck_assert_ptr_eq(s21_strcat(str4, str5), strcat(str4, str5));
}
END_TEST

START_TEST(test_s21_strncat) {
char str1[50] = "123";
char str2[50] = "Hello world\n\0";
char str3[50] = "a\n\0";
char str4[50] = " \n\0";
char str5[50] = " \0";
int n1 = 2;
int n2 = 5;

ck_assert_ptr_eq(s21_strncat(str1, str2, n1), strncat(str1, str2, n1));
ck_assert_ptr_eq(s21_strncat(str2, str3, n2), strncat(str2, str3, n2));
ck_assert_ptr_eq(s21_strncat(str3, str4, n1), strncat(str3, str4, n1));
ck_assert_ptr_eq(s21_strncat(str4, str5, n1), strncat(str4, str5, n1));
}
END_TEST

START_TEST(test_s21_strchr) {
char str1[20] = "12345678923";
char str2[20] = "";
char str3[20] = "Hello world\n\0";
int c1 = '2';
int c2 = '0';
int c4 = ' ';
ck_assert_ptr_eq(s21_strchr(str1, c1), strchr(str1, c1));
ck_assert_ptr_eq(s21_strchr(str1, c2), strchr(str1, c2));
ck_assert_ptr_eq(s21_strchr(str2, c2), strchr(str2, c2));
ck_assert_ptr_eq(s21_strchr(str3, c4), strchr(str3, c4));
}
END_TEST

START_TEST(test_s21_strcmp) {
char str1[20] = "Hello, world";
char str2[20] = "Hello, world";
char str3[20] = "";
char str4[20] = "";
char str5[20] = "12345\n";
char str6[20] = "     \n";
char str7[20] = "\n12345\0";
char str8[20] = "\"123 45\n\n\n\n\n";
char str9[20] = "\n\nabc";
char str10[20] = "abc";

ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
ck_assert_int_eq(s21_strcmp(str1, str3), strcmp(str1, str3));
ck_assert_int_eq(s21_strcmp(str3, str1), strcmp(str3, str1));
ck_assert_int_eq(s21_strcmp(str3, str4), strcmp(str3, str4));
ck_assert_int_eq(s21_strcmp(str1, str5), strcmp(str1, str5));
ck_assert_int_eq(s21_strcmp(str5, str6), strcmp(str5, str6));
ck_assert_int_eq(s21_strcmp(str5, str7), strcmp(str5, str7));
ck_assert_int_eq(s21_strcmp(str6, str8), strcmp(str6, str8));
ck_assert_int_eq(s21_strcmp(str9, str10), strcmp(str9, str10));
}
END_TEST

START_TEST(test_s21_strncmp) {
char str1[20] = "Hello, world";
char str2[20] = "Hello, world";
char str3[20] = "";
char str4[20] = "";
char str5[20] = "12345\n";
char str6[20] = "     \n";
char str7[20] = "\n12345\0";
char str8[20] = "\"123 45\n\n\n\n\n";
char str9[20] = "\n\nabc";
char str10[20] = "abc";
s21_size_t n1 = 2;
s21_size_t n2 = 5;
s21_size_t n3 = 0;
s21_size_t n4 = 10;

ck_assert_int_eq(s21_strncmp(str1, str2, n1), strncmp(str1, str2, n1));
ck_assert_int_eq(s21_strncmp(str1, str3, n1), strncmp(str1, str3, n1));
ck_assert_int_eq(s21_strncmp(str3, str1, n1), strncmp(str3, str1, n1));
ck_assert_int_eq(s21_strncmp(str3, str4, n1), strncmp(str3, str4, n1));
ck_assert_int_eq(s21_strncmp(str1, str5, n2), strncmp(str1, str5, n2));
ck_assert_int_eq(s21_strncmp(str5, str6, n4), strncmp(str5, str6, n4));
ck_assert_int_eq(s21_strncmp(str5, str7, n4), strncmp(str5, str7, n4));
ck_assert_int_eq(s21_strncmp(str6, str8, n4), strncmp(str6, str8, n4));
ck_assert_int_eq(s21_strncmp(str9, str10, n2), strncmp(str9, str10, n2));
ck_assert_int_eq(s21_strncmp(str1, str2, n3), strncmp(str1, str2, n3));
}
END_TEST

START_TEST(test_s21_strcpy) {
char str1[50] = "first string\0second string";
char str2[50] = "another string";
char str3[50] = "";
char str4[50] = "first string\0";

ck_assert_ptr_eq(s21_strcpy(&str1[13], str1), strcpy(&str1[13], str1));
ck_assert_ptr_eq(s21_strcpy(str2, str1), strcpy(str2, str1));
ck_assert_ptr_eq(s21_strcpy(str2, &str1[13]), strcpy(str2, &str1[13]));
ck_assert_ptr_eq(s21_strcpy(str3, str1), strcpy(str3, str1));
ck_assert_ptr_eq(s21_strcpy(str2, str3), strcpy(str2, str3));
ck_assert_ptr_eq(s21_strcpy(str2, &str4[13]), strcpy(str2, &str4[13]));
}
END_TEST

START_TEST(test_s21_strncpy) {
char str1[50] = "first string\0second string";
char str2[50] = "another string";
char str3[50] = "";
char str4[50] = "first string\0";
s21_size_t n1 = 5;
s21_size_t n2 = 0;
s21_size_t n3 = 20;

ck_assert_ptr_eq(s21_strncpy(&str1[13], str1, n1), strncpy(&str1[13], str1, n1));
ck_assert_ptr_eq(s21_strncpy(str2, str1, n1), strncpy(str2, str1, n1));
ck_assert_ptr_eq(s21_strncpy(str2, str1, n2), strncpy(str2, str1, n2));
ck_assert_ptr_eq(s21_strncpy(str2, str1, n3), strncpy(str2, str1, n3));
ck_assert_ptr_eq(s21_strncpy(str2, &str1[13], n1), strncpy(str2, &str1[13], n1));
ck_assert_ptr_eq(s21_strncpy(str3, str1, n1), strncpy(str3, str1, n1));
ck_assert_ptr_eq(s21_strncpy(str2, str3, n1), strncpy(str2, str3, n1));
ck_assert_ptr_eq(s21_strncpy(str2, &str4[13], n1), strncpy(str2, &str4[13], n1));
}
END_TEST

START_TEST(test_s21_strcspn) {
char str1[50] = "1234 563";
char str2[50] = "3";
char str3[50] = "";
char str4[50] = " \0";

ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
ck_assert_int_eq(s21_strcspn(str1, str3), strcspn(str1, str3));
ck_assert_int_eq(s21_strcspn(str1, str4), strcspn(str1, str4));
}
END_TEST

START_TEST(test_s21_strerror) {
float errnum1 = 44.5;
char errnum2 = 'a';

ck_assert_str_eq(s21_strerror(errnum1), strerror(errnum1));
ck_assert_str_eq(s21_strerror(errnum2), strerror(errnum2));

for (int i = -10; i < 150; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
}
}
END_TEST

START_TEST(test_s21_strlen) {
char str1[20] = "Hello world\0";
char str2[20] = "Hello world\n\0";
char str3[20] = "a\n\0";
char str4[20] = " \n\0";
char str5[20] = " \0";
char str6[20] = "\n\0";

ck_assert_int_eq(s21_strlen(str1), strlen(str1));
ck_assert_int_eq(s21_strlen(str2), strlen(str2));
ck_assert_int_eq(s21_strlen(str3), strlen(str3));
ck_assert_int_eq(s21_strlen(str4), strlen(str4));
ck_assert_int_eq(s21_strlen(str5), strlen(str5));
ck_assert_int_eq(s21_strlen(str6), strlen(str6));
}
END_TEST

START_TEST(test_s21_strpbrk) {
char str1[20] = "157";
char str2[20] = "12341";
char str3[20] = "23417";
char str4[20] = "2341576890";
char str5[20] = "2346890";
char str6[20] = "";
char str7[20] = "157-15789";
char str8[20] = "15715789";
char str9[20] = "15\0715789";
char str10[20] = " .!@\n";
char str11[20] = "\n @.@!!!f\0";

ck_assert_ptr_eq(s21_strpbrk(str2, str1), strpbrk(str2, str1));
ck_assert_ptr_eq(s21_strpbrk(str3, str1), strpbrk(str3, str1));
ck_assert_ptr_eq(s21_strpbrk(str4, str1), strpbrk(str4, str1));
ck_assert_ptr_eq(s21_strpbrk(str5, str1), strpbrk(str5, str1));
ck_assert_ptr_eq(s21_strpbrk(str6, str1), strpbrk(str6, str1));
ck_assert_ptr_eq(s21_strpbrk(str2, str6), strpbrk(str2, str6));
ck_assert_ptr_eq(s21_strpbrk(str6, str6), strpbrk(str6, str6));
ck_assert_ptr_eq(s21_strpbrk(str7, str1), strpbrk(str7, str1));
ck_assert_ptr_eq(s21_strpbrk(str8, str1), strpbrk(str8, str1));
ck_assert_ptr_eq(s21_strpbrk(str9, str1), strpbrk(str9, str1));
ck_assert_ptr_eq(s21_strpbrk(str11, str10), strpbrk(str11, str10));
}
END_TEST

START_TEST(test_s21_strrchr) {
char str1[20] = "12345678923";
char str2[20] = "";
char str3[20] = "Hello world\n\0";
int c1 = '2';
int c3 = '0';
int c4 = 'e';

ck_assert_ptr_eq(s21_strrchr(str1, c1), strrchr(str1, c1));
ck_assert_ptr_eq(s21_strrchr(str1, c3), strrchr(str1, c3));
ck_assert_ptr_eq(s21_strrchr(str2, c1), strrchr(str2, c1));
ck_assert_ptr_eq(s21_strrchr(str3, c4), strrchr(str3, c4));
}
END_TEST

START_TEST(test_s21_strspn) {
char str1[20] = "157";
char str2[20] = "12341";
char str3[20] = "23417";
char str4[20] = "2341576890";
char str5[20] = "2346890";
char str6[20] = "";
char str7[20] = "157-15789";
char str8[20] = "15715789";
char str9[20] = "15\n715789";
char str10[20] = " .!@\n";
char str11[20] = "\n @.@!!!f\0";

ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
ck_assert_int_eq(s21_strspn(str3, str1), strspn(str3, str1));
ck_assert_int_eq(s21_strspn(str4, str1), strspn(str4, str1));
ck_assert_int_eq(s21_strspn(str5, str1), strspn(str5, str1));
ck_assert_int_eq(s21_strspn(str6, str1), strspn(str6, str1));
ck_assert_int_eq(s21_strspn(str2, str6), strspn(str2, str6));
ck_assert_int_eq(s21_strspn(str6, str6), strspn(str6, str6));
ck_assert_int_eq(s21_strspn(str7, str1), strspn(str7, str1));
ck_assert_int_eq(s21_strspn(str8, str1), strspn(str8, str1));
ck_assert_int_eq(s21_strspn(str9, str1), strspn(str9, str1));
ck_assert_int_eq(s21_strspn(str11, str10), strspn(str11, str10));
}
END_TEST

START_TEST(test_s21_strstr) {
char str1[50] = "1234567956";
char str2[50] = "56";
char str3[50] = "Hello woerld\n\0";
char str4[50] = "e";
char str5[50] = "";

ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
ck_assert_ptr_eq(s21_strstr(str2, str3), strstr(str2, str3));
ck_assert_ptr_eq(s21_strstr(str3, str4), strstr(str3, str4));
ck_assert_ptr_eq(s21_strstr(str3, str5), strstr(str3, str5));
}
END_TEST

START_TEST(test_s21_strtok) {
char str1[20] = "123/456";
char str2[20] = "123///456/789";
char str3[50] = "   123///456/789  //\n";
char str4[50] = "";
char str5[50] = "123456789";
char delim1[20] = "/";
char delim2[20] = " /!@\n\t";
char delim3[20] = "";

ck_assert_ptr_eq(s21_strtok(str1, delim1), strtok(str1, delim1));
ck_assert_ptr_eq(s21_strtok(str2, delim1), strtok(str2, delim1));
ck_assert_ptr_eq(s21_strtok(str3, delim2), strtok(str3, delim2));
ck_assert_ptr_eq(s21_strtok(str3, delim3), strtok(str3, delim3));
ck_assert_ptr_eq(s21_strtok(str4, delim2), strtok(str4, delim2));
ck_assert_ptr_eq(s21_strtok(NULL, delim2), strtok(NULL, delim2));
ck_assert_ptr_eq(s21_strtok(str5, delim2), strtok(str5, delim2));
ck_assert_ptr_eq(s21_strtok(str5, delim3), strtok(str5, delim3));
}
END_TEST

START_TEST(test_s21_to_upper) {
char str1[20] = "abcdef";
char str2[20] = "aBcDeF123";
char str3[20] = "123/456";
char str4[20] = "";

ck_assert_str_eq(s21_to_upper(str1), "ABCDEF");
ck_assert_str_eq(s21_to_upper(str2), "ABCDEF123");
ck_assert_str_eq(s21_to_upper(str3), "123/456");
ck_assert_str_eq(s21_to_upper(str4), "");
}
END_TEST

START_TEST(test_s21_to_lower) {
char str1[20] = "abcdef";
char str2[20] = "aBcDeF123";
char str3[20] = "123/456";
char str4[20] = "";

ck_assert_str_eq(s21_to_lower(str1), "abcdef");
ck_assert_str_eq(s21_to_lower(str2), "abcdef123");
ck_assert_str_eq(s21_to_lower(str3), "123/456");
ck_assert_str_eq(s21_to_lower(str4), "");
}
END_TEST

START_TEST(test_s21_insert) {
char str1[20] = "abcdef";
char str2[20] = "123";
char str3[20] = " ";
s21_size_t n1 = 5;
s21_size_t n2 = 3;
s21_size_t n3 = 0;

ck_assert_str_eq(s21_insert(str1, str2, n1), "abcde123f");
ck_assert_str_eq(s21_insert(str1, str2, n3), "123abcdef");
ck_assert_str_eq(s21_insert(str2, str3, n2), "123 ");
}
END_TEST

START_TEST(test_s21_trim) {
if (Mac) {
char str1[20] = "!/! abcdef/ ";
char str2[20] = "!/";
char str3[20] = "!/ ";
char str4[20] = "";

ck_assert_str_eq(s21_trim(str1, str2), " abcdef/ ");
ck_assert_str_eq(s21_trim(str1, str3), "abcdef");
ck_assert_str_eq(s21_trim(str1, str4), "!/! abcdef/");
}
}
END_TEST

START_TEST(test_s21_sprintf) {
char str1[size] = {0};
char str2[size] = {0};

s21_sprintf(str1, "%%");
sprintf(str2, "%%");
ck_assert_str_eq(str1, str2);  // %%
s21_clean(str1, str2, size);

// %d with +, -,  , l, h, width, precision.

s21_sprintf(str1, "number: %d is good", 12345);
sprintf(str2, "number: %d is good", 12345);
ck_assert_str_eq(str1, str2);  // %d with text
s21_clean(str1, str2, size);

s21_sprintf(str1, "%d", 0);
sprintf(str2, "%d", 0);
ck_assert_str_eq(str1, str2);  // %d
s21_clean(str1, str2, size);

s21_sprintf(str1, "%-d", 12345);
sprintf(str2, "%-d", 12345);
ck_assert_str_eq(str1, str2);  // %-d
s21_clean(str1, str2, size);

s21_sprintf(str1, "%+d", 12345);
sprintf(str2, "%+d", 12345);
ck_assert_str_eq(str1, str2);  // %+d
s21_clean(str1, str2, size);

s21_sprintf(str1, "%+d", -12345);
sprintf(str2, "%+d", -12345);
ck_assert_str_eq(str1, str2);  // %+d with -number
s21_clean(str1, str2, size);

s21_sprintf(str1, "% d", 12345);
sprintf(str2, "% d", 12345);
ck_assert_str_eq(str1, str2);  // % d
s21_clean(str1, str2, size);

s21_sprintf(str1, "%+-5d", 12345);
sprintf(str2, "%+-5d", 12345);
ck_assert_str_eq(str1, str2);  // %+-d
s21_clean(str1, str2, size);

s21_sprintf(str1, "%ld", 2147483650);
sprintf(str2, "%ld", 2147483650);
ck_assert_str_eq(str1, str2);  // %ld
s21_clean(str1, str2, size);

s21_sprintf(str1, "%4d", 12345);
sprintf(str2, "%4d", 12345);
ck_assert_str_eq(str1, str2);  // %4d
s21_clean(str1, str2, size);

s21_sprintf(str1, "%8d", 12345);
sprintf(str2, "%8d", 12345);
ck_assert_str_eq(str1, str2);  // %8d
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.d", 12345);
sprintf(str2, "%.d", 12345);
ck_assert_str_eq(str1, str2);  // %.d
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.10d", 12345);
sprintf(str2, "%.10d", 12345);
ck_assert_str_eq(str1, str2);  // %.10d
s21_clean(str1, str2, size);

// %u with +, -,  , l, h, width, precision.

unsigned x = 12345;
unsigned x1 = 0;
long unsigned x2 = 4294967298;

s21_sprintf(str1, "%u", x);
sprintf(str2, "%u", x);
ck_assert_str_eq(str1, str2);  // %u
s21_clean(str1, str2, size);

s21_sprintf(str1, "%u", x1);
sprintf(str2, "%u", x1);
ck_assert_str_eq(str1, str2);  // %u
s21_clean(str1, str2, size);

s21_sprintf(str1, "%lu", x2);
sprintf(str2, "%lu", x2);
ck_assert_str_eq(str1, str2);  // %lu
s21_clean(str1, str2, size);

s21_sprintf(str1, "%-u", x);
sprintf(str2, "%-u", x);
ck_assert_str_eq(str1, str2);  // %-u
s21_clean(str1, str2, size);

s21_sprintf(str1, "%4u", x);
sprintf(str2, "%4u", x);
ck_assert_str_eq(str1, str2);  // %4u
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.u", x);
sprintf(str2, "%.u", x);
ck_assert_str_eq(str1, str2);  // %.u
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.10u", x);
sprintf(str2, "%.10u", x);
ck_assert_str_eq(str1, str2);  // %.10u
s21_clean(str1, str2, size);


// %c +, -, , width.

s21_sprintf(str1, "%c", 'a');
sprintf(str2, "%c", 'a');
ck_assert_str_eq(str1, str2);  // %c
s21_clean(str1, str2, size);

s21_sprintf(str1, "%-c", 'a');
sprintf(str2, "%-c", 'a');
ck_assert_str_eq(str1, str2);  // %-c
s21_clean(str1, str2, size);


// %s +, -, , width, precision.

s21_sprintf(str1, "%s", "abcd");
sprintf(str2, "%s", "abcd");
ck_assert_str_eq(str1, str2);  // %s
s21_clean(str1, str2, size);

s21_sprintf(str1, "%-2s", "abcd");
sprintf(str2, "%-2s", "abcd");
ck_assert_str_eq(str1, str2);  // %-2s
s21_clean(str1, str2, size);

s21_sprintf(str1, "%-s", "abcd");
sprintf(str2, "%-s", "abcd");
ck_assert_str_eq(str1, str2);  // %-s
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.s", "abcd");
sprintf(str2, "%.s", "abcd");
ck_assert_str_eq(str1, str2);  // %.s
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.5s", "Hello, world");
sprintf(str2, "%.5s", "Hello, world");
ck_assert_str_eq(str1, str2);  // %.5s
s21_clean(str1, str2, size);



// %f +, -, , l, width, precision.

s21_sprintf(str1, "%f", 123.123456);
sprintf(str2, "%f", 123.123456);
ck_assert_str_eq(str1, str2);  // %f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%-f", 123.123456);
sprintf(str2, "%-f", 123.123456);
ck_assert_str_eq(str1, str2);  // %-f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%+f %-f", 123.123456, -123.123456);
sprintf(str2, "%+f %-f", 123.123456, -123.123456);
ck_assert_str_eq(str1, str2);  // %+f %-f
s21_clean(str1, str2, size);

s21_sprintf(str1, "% f", 123.123456);
sprintf(str2, "% f", 123.123456);
ck_assert_str_eq(str1, str2);  // % f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%15f", 123.123456);
sprintf(str2, "%15f", 123.123456);
ck_assert_str_eq(str1, str2);  // %15f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%5f", 123.123456);
sprintf(str2, "%5f", 123.123456);
ck_assert_str_eq(str1, str2);  // %5f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.0f", 2.5);
sprintf(str2, "%.0f", 2.5);
ck_assert_str_eq(str1, str2);  // %f bank
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.0f", 7.5);
sprintf(str2, "%.0f", 7.5);
ck_assert_str_eq(str1, str2);  // %f bank
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.1f", 123.1234567890123456);
sprintf(str2, "%.1f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.1f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.2f", 123.1234567890123456);
sprintf(str2, "%.2f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.2f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.3f", 123.1234567890123456);
sprintf(str2, "%.3f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.3f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.4f", 123.1234567890123456);
sprintf(str2, "%.4f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.4f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.5f", 123.1234567890123456);
sprintf(str2, "%.5f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.5f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.6f", 123.1234567890123456);
sprintf(str2, "%.6f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.6f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.7f", 123.1234567890123456);
sprintf(str2, "%.7f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.7f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.8f", 123.1234567890123456);
sprintf(str2, "%.8f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.8f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.9f", 123.1234567890123456);
sprintf(str2, "%.9f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.9f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.10f", 123.1234567890123456);
sprintf(str2, "%.10f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.10f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.11f", 123.1234567890123456);
sprintf(str2, "%.11f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.11f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.12f", 123.1234567890123456);
sprintf(str2, "%.12f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.12f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.13f", 123.1234567890123456);
sprintf(str2, "%.13f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.13f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.14f", 123.1234567890123456);
sprintf(str2, "%.14f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.14f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.15f", 123.1234567890123456);
sprintf(str2, "%.15f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.15f
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.16f", 123.1234567890123456);
sprintf(str2, "%.16f", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.16f
s21_clean(str1, str2, size);


s21_sprintf(str1, "%lf", 123.1234567890123456);
sprintf(str2, "%lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%-lf", 123.123456);
sprintf(str2, "%-lf", 123.123456);
ck_assert_str_eq(str1, str2);  // %-lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%+lf %-lf", 123.123456, -123.123456);
sprintf(str2, "%+lf %-lf", 123.123456, -123.123456);
ck_assert_str_eq(str1, str2);  // %+lf %-lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "% lf", 123.123456);
sprintf(str2, "% lf", 123.123456);
ck_assert_str_eq(str1, str2);  // % lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%lf % lf %+lf %-lf %4lf %.5lf", 123.1234567890123456, 123.1234567890123456,
    123.1234567890123456, 123.1234567890123456, 123.1234567890123456, 123.1234567890123456);
sprintf(str2, "%lf % lf %+lf %-lf %4lf %.5lf", 123.1234567890123456, 123.1234567890123456,
    123.1234567890123456, 123.1234567890123456, 123.1234567890123456, 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %lf all
s21_clean(str1, str2, size);

s21_sprintf(str1, "%15lf", 123.123456);
sprintf(str2, "%15f", 123.123456);
ck_assert_str_eq(str1, str2);  // %15lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%5lf", 123.123456);
sprintf(str2, "%5lf", 123.123456);
ck_assert_str_eq(str1, str2);  // %5lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.0lf", 2.5);
sprintf(str2, "%.0lf", 2.5);
ck_assert_str_eq(str1, str2);  // %lf bank
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.0lf", 7.5);
sprintf(str2, "%.0lf", 7.5);
ck_assert_str_eq(str1, str2);  // %lf bank
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.1lf", 123.1234567890123456);
sprintf(str2, "%.1lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.1lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.2lf", 123.1234567890123456);
sprintf(str2, "%.2lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.2lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.3lf", 123.1234567890123456);
sprintf(str2, "%.3lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.3lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.4lf", 123.1234567890123456);
sprintf(str2, "%.4lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.4lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.5lf", 123.1234567890123456);
sprintf(str2, "%.5lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.5lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.6lf", 123.1234567890123456);
sprintf(str2, "%.6lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.6lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.7lf", 123.1234567890123456);
sprintf(str2, "%.7lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.7lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.8lf", 123.1234567890123456);
sprintf(str2, "%.8lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.8lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.9lf", 123.1234567890123456);
sprintf(str2, "%.9lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.9lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.10lf", 123.1234567890123456);
sprintf(str2, "%.10lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.10lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.11lf", 123.1234567890123456);
sprintf(str2, "%.11lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.11lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.12lf", 123.1234567890123456);
sprintf(str2, "%.12lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.12lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.13lf", 123.1234567890123456);
sprintf(str2, "%.13lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.13lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.14lf", 123.1234567890123456);
sprintf(str2, "%.14lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.14lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.15lf", 123.1234567890123456);
sprintf(str2, "%.15lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.15lf
s21_clean(str1, str2, size);

s21_sprintf(str1, "%.16lf", 123.1234567890123456);
sprintf(str2, "%.16lf", 123.1234567890123456);
ck_assert_str_eq(str1, str2);  // %.16lf
s21_clean(str1, str2, size);
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, test_s21_memchr);
    tcase_add_test(tc1_1, test_s21_memcmp);
    tcase_add_test(tc1_1, test_s21_memcpy);
    tcase_add_test(tc1_1, test_s21_memmove);
    tcase_add_test(tc1_1, test_s21_memset);
    tcase_add_test(tc1_1, test_s21_strcat);
    tcase_add_test(tc1_1, test_s21_strncat);
    tcase_add_test(tc1_1, test_s21_strchr);
    tcase_add_test(tc1_1, test_s21_strcmp);
    tcase_add_test(tc1_1, test_s21_strncmp);
    tcase_add_test(tc1_1, test_s21_strcpy);
    tcase_add_test(tc1_1, test_s21_strncpy);
    tcase_add_test(tc1_1, test_s21_strcspn);
    tcase_add_test(tc1_1, test_s21_strerror);
    tcase_add_test(tc1_1, test_s21_strlen);
    tcase_add_test(tc1_1, test_s21_strpbrk);
    tcase_add_test(tc1_1, test_s21_strrchr);
    tcase_add_test(tc1_1, test_s21_strspn);
    tcase_add_test(tc1_1, test_s21_strstr);
    tcase_add_test(tc1_1, test_s21_strtok);
    tcase_add_test(tc1_1, test_s21_to_upper);
    tcase_add_test(tc1_1, test_s21_to_lower);
    tcase_add_test(tc1_1, test_s21_insert);
    tcase_add_test(tc1_1, test_s21_trim);
    tcase_add_test(tc1_1, test_s21_sprintf);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
