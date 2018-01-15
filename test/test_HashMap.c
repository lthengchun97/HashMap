#include "unity.h"
#include "Data.h"
#include "linkedlist.h"
#include "HashMap.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include "integerCompare.h"
#include "Compare.h"
#include "HashMapString.h"
#include "Exception.h"
#include "CException.h"

CEXCEPTION_T ex;
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
    Try{
      _hashMapAdd(&table,(void *)data,5,7,(Compare) integerKeyCompare);
    }
    Catch(ex)
    {
      dumpException(ex);
    }

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
    Try{
      david=dataCreate(5,"David");
      _hashMapAdd(&table,(void *)david,5,7,(Compare) integerKeyCompare);
      ali = dataCreate(3,"Ali");
      _hashMapAdd(&table,(void *)ali,3,7,(Compare) integerKeyCompare);

      TEST_ASSERT_NOT_NULL(table.list[7].head);
      data = (Data *)(table.list[7].head->data);
      TEST_ASSERT_EQUAL(5,data->key);
      TEST_ASSERT_EQUAL_STRING("David",data->name);

      TEST_ASSERT_NOT_NULL(table.list[7].head->next);
      data = (Data *)(table.list[7].head->next->data);
      TEST_ASSERT_EQUAL(3,data->key);
      TEST_ASSERT_EQUAL_STRING("Ali",data->name);


      TEST_ASSERT_NULL(table.list[7].head->next->next);
    }
    Catch(ex)
    {
      dumpException(ex);
    }

    free(david);
    free(ali);
}

void test__testMapSearch_given_values_5_and_3_in_the_table_then_search_for_3_Ali(void){
  Data *data, *david , *ali;
  HashTable table;
  hashMapInit(&table,10);
  Try{
  david = dataCreate(5,"David");
  _hashMapAdd(&table,(void *)david,5,7,(Compare) integerKeyCompare);
  ali = dataCreate(3,"Ali");
  _hashMapAdd(&table,(void *)ali,3,7,(Compare) integerKeyCompare);
  data = (Data *)_hashMapSearch(&table,ali->key,7,(Compare) integerKeyCompare);
  TEST_ASSERT_NOT_NULL(data);
  TEST_ASSERT_EQUAL(3,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);
}

Catch(ex)
{
  dumpException(ex);
}
  free(david);
  free(ali);
}



void test_hashMapAddInteger_given_empty_hash_table_and_add_2_values_with_different_keys(void)
{
    HashTable table;
    hashMapInit(&table,25);
    hashMapAddInteger(&table,(void *)17,7);
    hashMapAddInteger(&table,(void *)6,8);

    Data* head=table.list[17].head->data;
    TEST_ASSERT_NOT_NULL(table.list[17].head);
    TEST_ASSERT_EQUAL(17,head->value);
    TEST_ASSERT_EQUAL(7,head->key);
    TEST_ASSERT_EQUAL(6,table.list[6].head->data->value);
    TEST_ASSERT_EQUAL(8,table.list[6].head->data->key);

}

void test__hashMapAdd_given_empty_hash_table_and_value_5_is_added_expect_5_inserted(void)
{
    HashTable table;
    hashMapInit(&table,10);
    _hashMapAdd(&table,(void *)5,0,7,(Compare) integerKeyCompare);
    TEST_ASSERT_NOT_NULL(table.list[7].head);
    TEST_ASSERT_EQUAL(5,(int*)(table.list[7].head->data));
}

void test__hashMapRemove_given_ali_and_david_then_remove_ali_expected_ali_removed(void){
  Data *data,*david,*ali,*data1;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  Try{
  david = dataCreate(5,"David");
  _hashMapAdd(&hashTable,(void *)david, 5,7,(Compare) integerKeyCompare);
  ali = dataCreate(3,"Ali");
  _hashMapAdd(&hashTable,(void *)ali, 3,7,(Compare) integerKeyCompare);

  data =  (Data *)(hashTable.list[7].head->next);
  TEST_ASSERT_NOT_NULL(data);
  data = (Data *)_hashMapRemove(&hashTable,ali->key,7,(Compare) integerKeyCompare);
  TEST_ASSERT_EQUAL(3,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);
  data =  (Data *)(hashTable.list[7].head->next);
  TEST_ASSERT_NULL(data);
}
Catch(ex)
{
  dumpException(ex);
}
  free(david);
  free(ali);
}

void test__hashMapSearch_given_ali_and_david_then_search_ali(void){
  Data *data,*david,*ali,*data1;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  Try{
  david = dataCreate(5,"David");
  _hashMapAdd(&hashTable,(void *)david, 5,7,(Compare) integerKeyCompare);
  ali = dataCreate(5,"Ali");
  _hashMapAdd(&hashTable,(void *)ali, 5,7,(Compare) integerKeyCompare);

  data = (Data *)_hashMapSearch(&hashTable,ali->key,7,(Compare) integerKeyCompare);
  TEST_ASSERT_NOT_NULL(data);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);
  data =  (Data *)(hashTable.list[7].head->next);
  TEST_ASSERT_NULL(data);

  //data = (Data *)_hashMapRemove(&hashTable,ali->key,7,(Compare) integerKeyCompare);
  //TEST_ASSERT_EQUAL(3,data->key);
  //TEST_ASSERT_EQUAL_STRING("Ali",data->name);
}
Catch(ex)
{
  dumpException(ex);
}
  free(david);
  free(ali);
}

void test_hashMapAddString_Given_empty_hash_table_and_Ali_David(void){
  Data *data,*ali,*david;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  Try{
  david = dataCreate(5,"David");
  hashMapAddString(&hashTable,"David",5);
  ali = dataCreate(8,"Ali");
  hashMapAddString(&hashTable,"Ali",8);

  TEST_ASSERT_EQUAL(hashTable.list[5].head->data->name,"David");
  TEST_ASSERT_EQUAL(hashTable.list[8].head->data->name,"Ali");
  TEST_ASSERT_NULL(hashTable.list[5].head->next);
  TEST_ASSERT_NULL(hashTable.list[8].head->next);
}
Catch(ex)
{
  dumpException(ex);
}
  free(david);
  free(ali);
}

void test_hashMapRemoveString_given_David_and_Ali_then_remove_David(void){
  Data *data,*data1,*ali,*david;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  Try{
  david = dataCreate(5,"David");
  hashMapAddString(&hashTable,"David",5);
  ali = dataCreate(6,"Ali");
  hashMapAddString(&hashTable,"Ali",6);

  TEST_ASSERT_EQUAL(hashTable.list[5].head->data->name,"David");
  data =  (Data *)(hashTable.list[5].head->data->name);
  TEST_ASSERT_NOT_NULL(data);
  hashMapRemoveString(&hashTable,"David",5);
  data1 =  (Data *)(hashTable.list[5].head->next);
  TEST_ASSERT_NULL(data1);
  }
  Catch(ex)
  {
    dumpException(ex);
  }
  free(david);
  free(ali);

}

void test_hashMapSearchString_given_David_Ali_then_search_Ali_expected_Ali_return(void){
  Data *data1,*david,*ali;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  Try{
  david = dataCreate(5,"David");
  hashMapAddString(&hashTable,(void *)david,5);
  ali = dataCreate(8,"Ali");
  hashMapAddString(&hashTable,(void *)ali,8);

  data1=(Data *)hashMapSearchString(&hashTable,(void *)ali,8);
  TEST_ASSERT_NOT_NULL(data1);
  //TEST_ASSERT_EQUAL(8,data1->key);
  //TEST_ASSERT_EQUAL_STRING("Ali",data1->name);
  }
  Catch(ex)
  {
    dumpException(ex);
  }
  free(david);
  free(ali);

}
