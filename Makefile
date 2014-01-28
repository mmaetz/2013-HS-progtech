all: slides exercises

slides:
	latexmk -pdf --pdflatex="pdflatex --shell-escape" main.tex

exercises:
	latexmk -pdf --pdflatex="pdflatex --shell-escape" exercises.tex

examples:
	latexmk -pdf --pdflatex="pdflatex --shell-escape" lecture-examples.tex

s-pvc:
	latexmk -pdf -pvc --pdflatex="pdflatex --shell-escape" main.tex

e-pvc:
	latexmk -pdf -pvc --pdflatex="pdflatex --shell-escape" exercises.tex

clean:
	rm *.aux
	rm *.log
	rm *.pdf
	rm *.toc
	rm *.out
	rm *.fdb_latexmk
