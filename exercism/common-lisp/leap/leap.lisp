(defpackage #:leap
  (:use #:common-lisp)
  (:export #:leap-year-p))
(in-package #:leap)

;; Simple solution

;; (defun leap-year-p (year)
;;   (defun divisiblep (num)
;;     (zerop (mod year num)))
;;   (cond ((divisiblep 400) t)
;;         ((divisiblep 100) nil)
;;         ((divisiblep 4) t)))

(defun list-to-pairs (l)
  "'(1 2 3 4) -> '((1 2) (3 4))"
  (loop for (a b) on l
        :by #'cddr
        collect (cons a b)))

(defun divisible-p (num base)           ; Can (NUM YEAR)
  (zerop (mod base num)))

(defmacro div-case (year &body body)
  "Return the number num where,year (mod num) = 0"
  (let ((parsed (list-to-pairs body)))
    `(cond
       ,@(loop for (num . res) in parsed
               collect `((divisible-p ,num ,year) ,res)))))

(defun leap-year-p (year)
  (div-case year
    400 t
    100 nil
    4 t))
