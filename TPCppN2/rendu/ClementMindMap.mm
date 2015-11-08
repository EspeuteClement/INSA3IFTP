<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1446924719176" ID="ID_273007821" MODIFIED="1446984116471" TEXT="New Mindmap">
<node CREATED="1446924724810" ID="ID_1519447860" MODIFIED="1446924731972" POSITION="right" TEXT="Utils">
<node CREATED="1446924833530" ID="ID_230806177" MODIFIED="1446924938574" TEXT="Sert &#xe0; g&#xe9;r&#xe9;r quelques commandes qui no&apos;nt pas vraiement leurs place dans une des autres classes, comme max() et impression de message en couleur pour les tests"/>
</node>
<node CREATED="1446924734444" ID="ID_1774060257" MODIFIED="1446924737867" POSITION="right" TEXT="IoEngine">
<node CREATED="1446924950662" ID="ID_531812520" MODIFIED="1446924960335" TEXT="Gere toutes les entr&#xe9;es sorties de l&apos;application"/>
<node CREATED="1446924960595" ID="ID_1614329180" MODIFIED="1446925299201" TEXT="La classe comporte une &quot;collone vert&#xe9;brale&quot; sous la forme de la methode ReadInput(), qui attends que l&apos;utilisateur entre le code de la commande a executer (ADD, STATS_C etc...). Elle poss&#xe8;de aussi un BinaryTree qui lui est propre. Elle appele ensuite des sous fonctions qui corespondent &#xe0; ces commande, qui ont toutes pour nom Handle&lt;nom_de_la_commande&gt;. Ces fonctions g&#xe8;rent la lecture de leurs param&#xe8;tres (car ils diff&#xe8;rents selon les fonctions). Elles modifient ou lisent ensuite les donn&#xe9;es du BinaryTree. Cette approche modulaire rend le code tr&#xe8;s lisible et permet de d&#xe9;sativer une commande dans impacter les autres."/>
</node>
<node CREATED="1446924738224" ID="ID_1290362258" MODIFIED="1446926284085" POSITION="right" TEXT="BinaryTree">
<node CREATED="1446924746175" ID="ID_1259294496" MODIFIED="1446927851416" TEXT="Node">
<node CREATED="1446927222973" ID="ID_1850787744" MODIFIED="1446927845435" TEXT="Chaque node fonctionne peut fonctionner comme un mini arbre binaire, et ceci est du au fait que toutes les m&#xe9;thodes qui modifient l&apos;&#xe9;tat des nodes agissent r&#xe9;cursivement sur les parents et enfants des Nodes."/>
<node CREATED="1446927854524" ID="ID_1173839030" MODIFIED="1446927854524" TEXT=""/>
</node>
<node CREATED="1446925303917" ID="ID_1356252531" MODIFIED="1446926277285" TEXT="BynaryTree agit comme une surcouche a node, car Node se comporte en r&#xe9;alit&#xe9; d&#xe9;j&#xe0; comme un arbre binaire, &#xe0; peu de choses pr&#xe8;s. N&#xe9;amoins, la classe ajoute quelques m&#xe9;thodes utiles comme un iterateur qui permet de r&#xe9;cup&#xe8;rer chaque &#xe9;l&#xe9;ment dans l&apos;arbre."/>
<node CREATED="1446926302772" ID="ID_512210781" MODIFIED="1446926302772" TEXT=""/>
</node>
<node CREATED="1446924768647" ID="ID_1047271021" MODIFIED="1446924772759" POSITION="left" TEXT="TestEngine"/>
<node CREATED="1446984118571" ID="ID_1612289542" MODIFIED="1446984125643" POSITION="left" TEXT="Ouside tools">
<node CREATED="1446984127083" ID="ID_845145270" MODIFIED="1446984137131" TEXT="dispTree">
<node CREATED="1446984571337" ID="ID_55690492" MODIFIED="1446984674002" TEXT="Petit programme &#xe9;crit &#xe0; l&apos;aide du framework lua L&#xd6;VE2d, il permet d&apos;afficher un arbre binaire. Il prends en entr&#xe9;e une table lua, export&#xe9;e depuis le programme a l&apos;aide de la methode BinaryTree::Serialize()."/>
</node>
</node>
</node>
</map>
