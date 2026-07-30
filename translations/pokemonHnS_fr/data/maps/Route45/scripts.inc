Route45_MapScripts::
	.byte 0

Route45_EventScript_Erik::
	trainerbattle_single TRAINER_ERIK Route45_Text_HikerErikSeen, Route45_Text_HikerErikBeaten
	msgbox Route45_Text_HikerErikAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Michael::
	trainerbattle_single TRAINER_MICHAEL Route45_Text_HikerMichaelSeen, Route45_Text_HikerMichaelBeaten
	msgbox Route45_Text_HikerMichaelAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Parry::
	trainerbattle_single TRAINER_PARRY Route45_Text_HikerParrySeen, Route45_Text_HikerParryBeaten
	msgbox Route45_Text_HikerParryAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY Route45_Text_HikerTimothySeen, Route45_Text_HikerTimothyBeaten
	msgbox Route45_Text_HikerTimothyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kenji::
	trainerbattle_single TRAINER_KENJI Route45_Text_BlackbeltKenjiSeen, Route45_Text_BlackbeltKenjiBeaten
	msgbox Route45_Text_BlackbeltKenjiAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Ryan::
	trainerbattle_single TRAINER_RYAN Route45_Text_CooltrainermRyanSeen, Route45_Text_CooltrainermRyanBeaten
	msgbox Route45_Text_CooltrainermRyanAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kelly::
	trainerbattle_single TRAINER_KELLY Route45_Text_CooltrainerfKellySeen, Route45_Text_CooltrainerfKellyBeaten
	msgbox Route45_Text_CooltrainerfKellyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Quentin::
	trainerbattle_single TRAINER_QUENTIN Route45_Text_CamperQuentinSeen, Route45_Text_CamperQuentinBeaten
	msgbox Route45_Text_CamperQuentinAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Sign::
	msgbox Route45_Text_Sign, MSGBOX_SIGN
	end

Route45_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route45_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end

Route45_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

Route45_EventScript_Item_Nugget::
	finditem ITEM_NUGGET
	end

Route45_Text_HikerErikSeen:
    .string "Sois prêt à tout !\p"
    .string "Voyons si tes POKéMON ont\n"
    .string "été bien élevés !$"

Route45_Text_HikerErikBeaten:
    .string "Oh, j'ai perdu !$"

Route45_Text_HikerErikAfter:
    .string "Je retournerai au SENTIER GLACÉ\n"
    .string "d'ÉBENELLE pour m'entraîner davantage.$"

Route45_Text_HikerMichaelSeen:
    .string "Yo ! Tu as du cran ! Mais tu sais\n"
    .string "quoi ?\p"
    .string "Quand il s'agit de pur\n"
    .string "cran, c'est moi le boss !$"

Route45_Text_HikerMichaelBeaten:
    .string "Mes POKéMON n'étaient pas assez fougueux !$"

Route45_Text_HikerMichaelAfter:
    .string "Mon dieu, j'adore les PV PLUS ! Mmmm, délicieux !\p"
    .string "Je bois ceux de mes POKéMON !\p"
    .string "Je ne peux pas m'en empêcher !$"

Route45_Text_HikerParrySeen:
    .string "Mes POKéMON sont bourrés de puissance !$"

Route45_Text_HikerParryBeaten:
    .string "Wahahah ! Je suis le grand perdant !$"

Route45_Text_HikerParryAfter:
    .string "Je ne suis pas doué pour réfléchir,\n"
    .string "tu vois ?\p"
    .string "Alors, j'avance avec la force !$"


Route45_Text_HikerTimothySeen:
    .string "Pourquoi je grimpe les montagnes ?\p"
    .string "Parce qu'elles sont là.\p"
    .string "Pourquoi j'entraîne des POKéMON ?\p"
    .string "Parce qu'ils sont là !$"

Route45_Text_HikerTimothyBeaten:
    .string "Les défaites… Elles font partie du jeu !$"

Route45_Text_HikerTimothyAfter:
    .string "La meilleure chose qui me soit arrivée\n"
    .string "c'est d'avoir découvert les POKéMON.$"

Route45_Text_HikerParryGivesIron:
    .string "Je n'arrive tout simplement pas à\p"
    .string "gagner ! Continue comme ça !\p"
    .string "Ah, et prends ça, c'est le\n"
    .string "cadeau que tu n'as pas\n"
    .string "pu prendre la dernière fois.$"

Route45_Text_BlackbeltKenjiSeen:
    .string "Je m'entraînais ici, seul.\p"
    .string "Admire le fruit de mon travail !$"

Route45_Text_BlackbeltKenjiBeaten:
    .string "Waaaargh !$"

Route45_Text_BlackbeltKenjiAfter:
    .string "Il faut prendre des mesures extrêmes.\p"
    .string "Je dois partir dans les collines et m'entraîner\n"
    .string "en solitude.$"

Route45_Text_BlackbeltKenjiMorning:
    .string "Je vais encore m'entraîner un peu\n"
    .string "avant la pause déjeuner.$"

Route45_Text_BlackbeltKenjiNight:
    .string "On s'est bien reposés à midi,\p"
    .string "Alors on est prêts à repartir !\p"
    .string "On va s'entraîner encore !$"

Route45_Text_CooltrainermRyanSeen:
    .string "Que penses-tu de l'éducation\n"
    .string "des POKéMON ?$"

Route45_Text_CooltrainermRyanBeaten:
    .string "Tu as gagné mon respect.$"

Route45_Text_CooltrainermRyanAfter:
    .string "Je vois que tu élèves tes POKéMON\n"
    .string "avec soin.\p"
    .string "Le lien que vous créez vous sauvera\n"
    .string "dans les moments difficiles.$"

Route45_Text_CooltrainerfKellySeen:
    .string "Quelle est ta stratégie de combat ?\p"
    .string "Il est insensé d'utiliser des attaques\n"
    .string "puissantes sans réfléchir.$"

Route45_Text_CooltrainerfKellyBeaten:
    .string "Bon. J'ai perdu.$"

Route45_Text_CooltrainerfKellyAfter:
    .string "Je ne suis pas favorable aux attaques\n"
    .string "trop puissantes.\p"
    .string "Je veux gagner, mais je ne veux pas\n"
    .string "blesser les POKéMON.$"

Route45_Text_CamperQuentinSeen:
    .string "Je suis vraiment, vraiment costaud !$"

Route45_Text_CamperQuentinBeaten:
    .string "J'étais fort à la COLLINE DRESSEUR…$"

Route45_Text_CamperQuentinAfter:
    .string "Tu es allé à la COLLINE DES DRESSEURS ?\p"
    .string "Je ne perds jamais là-bas, mais…$"

Route45_Text_Sign:
    .string "ROUTE 45\n"
    .string "ROUTE MONTAGNE EN VUE$"
