all:
	latexmk -pdf -pvc --pdflatex="pdflatex --shell-escape" main.tex

clean:
	rm *.aux
	rm *.log
	rm *.pdf
	rm *.toc
	rm *.out
	rm *.fdb_latexmk
