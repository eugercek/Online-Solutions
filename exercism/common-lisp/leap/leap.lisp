(defpackage #:leap
  (:use #:common-lisp)
  (:export #:leap-year-p))
(in-package #:leap)

(defun leap-year-p (year)
  (defun divisiblep (num)
    (zerop (mod year num)))
  (cond ((divisiblep 400) t)
        ((divisiblep 100) nil)
        ((divisiblep 4) t)))
