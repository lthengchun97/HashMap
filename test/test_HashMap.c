#include "unity.h"
#include "Data.h"
#include "linkedlist.h"
#include "HashMap.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include "integerCompare.h"
#include "Compare.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_hashMapInit_given_a_table_and_a_size(void)
{
    HashTable table;
    hashMapInit(&table,10);
    TEST_ASSERT_NOT_NULL(table.list);
}

void test__hashMapAdd_given_empty_hash_table_and_value_5_is_added_expect_5_inserted_v1(void)
{
    Data *data;
    HashTable table;
    hashMapInit(&table,10);
    data=dataCreate(5,"David");
    _hashMapAdd(&table,(void *)data,7);

    TEST_ASSERT_NOT_NULL(table.list[7].head);
    data = (Data *)(table.list[7].head->data);
    TEST_ASSERT_EQUAL(5,data->key);
    TEST_ASSERT_EQUAL_STRING("David",data->name);
    free(data);
}

void test__hashMapAdd_given_empty_hash_table_and_value_5_is_added_expect_5_inserted_v2(void)
{
    Data *data , *david , *ali;
    HashTable table;
    hashMapInit(&table,10);
    david=dataCreate(5,"David");
    _hashMapAdd(&table,(void *)david,7);
    ali = dataCreate(3,"Ali");
    _hashMapAdd(&table,(void *)ali,7);

    TEST_ASSERT_NOT_NULL(table.list[7].head);
    data = (Data *)(table.list[7].head->data);
    TEST_ASSERT_EQUAL(5,data->key);
    TEST_ASSERT_EQUAL_STRING("David",data->name);

    TEST_ASSERT_NOT_NULL(table.list[7].head->next);
    data = (Data *)(table.list[7].head->next->data);
    TEST_ASSERT_EQUAL(3,data->key);
    TEST_ASSERT_EQUAL_STRING("Ali",data->name);


    TEST_ASSERT_NULL(table.list[7].head->next->next);
    free(david);
    free(ali);
}

void test__testMapSearch_given_values_5_and_3_in_the_table_then_search_for_3_Ali(void){
  Data *data, *david , *ali;
  HashTable table;
  hashMapInit(&table,10);

  david = dataCreate(5,"David");
  _hashMapAdd(&table,(void *)david,7);
  ali = dataCreate(3,"Ali");
  _hashMapAdd(&table,(void *)ali,7);

  data = (Data *)_hashMapSearch(&table,ali->key,7,(Compare) integerKeyCompare);

  TEST_ASSERT_NOT_NULL(data);
  TEST_ASSERT_EQUAL(3,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);
  free(david);
  free(ali);
}



void test__hashMapAdd_given_empty_hash_table_and_value_5_is_added_expect_5_inserted_v3(void)
{
    Data *data,*data1;
    HashTable table;
    hashMapInit(&table,25);
    hashMapAddInteger(&table,(void *)17,7);
    hashMapAddInteger(&table,(void *)6,8);

    TEST_ASSERT_NOT_NULL(table.list[17].head);
    TEST_ASSERT_EQUAL(17,table.list[17].head->data);
    //TEST_ASSERT_EQUAL(7,table.list[17].head->data->key);

    //TEST_ASSERT_NOT_NULL(table.list[6].head->next);
    //data1 = (Data *)(table.list[6].head->data);
    TEST_ASSERT_EQUAL(6,table.list[6].head->data);
    //TEST_ASSERT_EQUAL(6,data->value);
    //TEST_ASSERT_NULL(table.list[7].head->next->next);
    //free(david);
    //free(ali);

}

void test__hashMapAdd_given_empty_hash_table_and_value_5_is_added_expect_5_inserted(void)
{
    HashTable table;
    hashMapInit(&table,10);
    _hashMapAdd(&table,(void *)5,7);
    TEST_ASSERT_NOT_NULL(table.list[7].head);
    TEST_ASSERT_EQUAL(5,(int*)(table.list[7].head->data));
}

/**
  * index
  *       -------
  *       /     /
  *   7   /     /   -----> 5 --> 3
  *       /     /
  *       /     /
  **/


void test__hashMapAdd_given_values_5_and_3_are_added_expect_the_data_int_the_list_at_index_7(void)
{
    HashTable table;
    hashMapInit(&table,10);
    _hashMapAdd(&table,(int *)5,7);
    _hashMapAdd(&table,(int *)3,7);

    TEST_ASSERT_NOT_NULL(table.list[7].head);
    TEST_ASSERT_EQUAL(5,(int*)(table.list[7].head->data));
    TEST_ASSERT_NOT_NULL((int*)(table.list[7].head->next));
    TEST_ASSERT_EQUAL(3,(int*)(table.list[7].head->next->data));
    TEST_ASSERT_NULL((int*)(table.list[7].head->next->next));
}

/**
  * index
  *       -------
  *       /     /
  *   7   /     /   -----> 5 --> 3 --> 5
  *       /     /
  *       /     /
  **/


void test__hashMapAdd_given_values_5_and_3_are_added_expect_the_data_int_the_list_with_duplicate(void)
{
    HashTable table;
    hashMapInit(&table,10);
    _hashMapAdd(&table,(void *)5,7);
    _hashMapAdd(&table,(void *)3,7);
    _hashMapAdd(&table,(void *)5,7);

    TEST_ASSERT_NOT_NULL(table.list[7].head);
    TEST_ASSERT_EQUAL(5,(int*)(table.list[7].head->data));
    TEST_ASSERT_NOT_NULL((int*)(table.list[7].head->next));
    TEST_ASSERT_EQUAL(3,(int*)(table.list[7].head->next->data));
    TEST_ASSERT_NOT_NULL((int*)(table.list[7].head->next->next));
    TEST_ASSERT_EQUAL(5,(int*)(table.list[7].head->next->next->data));
    TEST_ASSERT_NULL((int*)(table.list[7].head->next->next->next));
}


void test__hashMapAdd_given_empty_hash_table_and_value_5_with_hash_value_of_4_expect_exception_be_thrown(void)
{
    //HashTable table;
    //hashMapInit(&table,3);
    //_hashMapAdd(&table,(void *)5,4);
    //TEST_ASSERT_NOT_NULL(table.list[7]);
}

void test__hashMapRemove_given_5_3_then_remove_3_expected_3_removed(void){
  Data *data,*david,*ali,*data1;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  david = dataCreate(5,"David");
  _hashMapAdd(&hashTable,(void *)david, 7);
  ali = dataCreate(3,"Ali");
  _hashMapAdd(&hashTable,(void *)ali, 7);

  data =  (Data *)(hashTable.list[7].head->next);
  TEST_ASSERT_NOT_NULL(data);
  data = (Data *)_hashMapRemove(&hashTable,ali->key,7,(Compare) integerKeyCompare);
  TEST_ASSERT_EQUAL(3,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);
  data =  (Data *)(hashTable.list[7].head->next);
  TEST_ASSERT_NULL(data);
  free(david);
  free(ali);
}
