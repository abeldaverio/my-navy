/*
** EPITECH PROJECT, 2024
** unit tests
** File description:
** unit tests for criterion
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "functions.h"

int GLOBAL = 0;

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (coord_line_true, test1, .init=redirect_all_stdout)
{
    cr_assert_eq(true, check_coord_line("2:C3:C4\n", 0));
    cr_assert_eq(true, check_coord_line("3:D4:F4\n", 1));
    cr_assert_eq(true, check_coord_line("4:A1:A4\n", 2));
    cr_assert_eq(true, check_coord_line("5:F8:F4\n", 3));
}

Test (coord_line_false, test1, .init=redirect_all_stdout)
{
    cr_assert_eq(false, check_coord_line("1:C2:C3\n", 0));
    cr_assert_eq(false, check_coord_line("2:C2:C3\n", 1));
    cr_assert_eq(false, check_coord_line("3:D4:F3\n", 0));
    cr_assert_eq(false, check_coord_line("0:B1:A4\n", 2));
    cr_assert_eq(false, check_coord_line("prout5:F7:F4\n", 3));
    cr_assert_eq(false, check_coord_line("5:F8:F4yeah\n", 3));
    cr_assert_eq(false, check_coord_line("LQKVDHDLQ", 0));
}

Test (coordinates_true, test3, .init=redirect_all_stdout)
{
    cr_assert_eq(true, check_coordinates("2:C3:C4\n", 2));
    cr_assert_eq(true, check_coordinates("3:D4:F4\n", 3));
    cr_assert_eq(true, check_coordinates("4:A1:A4\n", 4));
    cr_assert_eq(true, check_coordinates("5:F8:F4\n", 5));
}

Test (coordinates_false, test4, .init=redirect_all_stdout)
{
    cr_assert_eq(false, check_coordinates("2:C3:C5\n", 2));
    cr_assert_eq(false, check_coordinates("3:A2:F4\n", 1));
    cr_assert_eq(false, check_coordinates("4:A1:D4\n", 4));
    cr_assert_eq(false, check_coordinates("5:F8:F4\n", 3));
}
