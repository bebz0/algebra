#ifndef _POLYGONE_H_
#define _POLYGONE_H_

#include <stdio.h>
#include "Types.h" // Ваш файл з визначенням TPoint, Polygone, etc.

// --- ЗАВДАННЯ А-Д: ОСНОВНІ ОПЕРАЦІЇ З ФАЙЛАМИ ---

// а) Додавання багатокутника з консолі у файл
void add_polygone_from_console(const char *filename);

// б) Додавання всіх багатокутників з файлу-джерела у файл-призначення
void append_polygons_from_file(const char *dest_filename, const char *src_filename);

// в) Виведення всіх багатокутників з файлу на консоль
void display_all_polygons(const char *filename);

// г) Виведення багатокутника за індексом на консоль
void display_polygone_by_index(const char *filename, NTYPE index);

// д) Видалення багатокутника за індексом з файлу
int delete_polygone_by_index(const char *filename, NTYPE index);

// --- ЗАВДАННЯ Е-І: АНАЛІЗ ТА ПОШУК ---

// е) Перевірка, чи є даний багатокутник у файлі
int is_present_in_file(const char *filename, const Polygone *p);

// є) Пошук багатокутника з максимальним периметром
int find_max_perimeter_polygone(const char *filename, Polygone *result);

// ж) Пошук багатокутника з мінімальною площею
int find_min_area_polygone(const char *filename, Polygone *result);

// з) Підрахунок кількості опуклих багатокутників у файлі
NTYPE count_convex_polygons(const char *filename);

// і) Кількість багатокутників, що містять точку Р
NTYPE count_polygons_containing_point(const char *filename, TPoint p);

// --- ЗАВДАННЯ Й: ФІЛЬТРАЦІЯ ---

// й) Фільтрація багатокутників за умовою (предикатом) у новий файл
void filter_polygons(const char *file_a, const char *file_b, int (*predicate)(const Polygone *));

// --- ДОПОМІЖНІ ГЕОМЕТРИЧНІ ФУНКЦІЇ (ЗАВДАННЯ К) ---

PTYPE perimeter_polygone(const Polygone *p);
PTYPE area_polygone(const Polygone *p);
int is_convex(const Polygone *p);
int is_point_inside(const Polygone *p, TPoint point);

// --- ДОПОМІЖНІ ФУНКЦІЇ ЗАГАЛЬНОГО ПРИЗНАЧЕННЯ ---

int isEqualPoint(TPoint a, TPoint b);
int isEqualPolygone(const Polygone *p1, const Polygone *p2);
void free_polygone(Polygone *p);

#endif // _POLYGONE_H_