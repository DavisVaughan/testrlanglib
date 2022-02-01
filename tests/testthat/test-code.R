test_that("can detect doubles", {
  expect_true(test_is_double(1))
  expect_false(test_is_double(1L))
})
