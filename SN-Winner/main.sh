clear
echo "Qual o nome a apresentar?"
read nome
echo ""
echo "O user é: $nome na data $(date):"
echo ""
echo "sim ou não?"
read resposta
if [ $resposta = "sim" ] 
  then
  echo "Parabéns!"
elif [ $resposta = "não" ] 
  then
  echo "Não estudou !!!"
else
  echo "Não conheço a resposta $resposta. Introduza sim ou não!"
fi
