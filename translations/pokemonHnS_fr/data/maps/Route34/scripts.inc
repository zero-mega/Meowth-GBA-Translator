.set LOCALID_ROUTE34_DAYCAREMAN, 12

Route34_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route34_OnTransition: 
	specialvar VAR_RESULT, GetDaycareState
	call_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_MapScript_EggReady
	callnative SetTimeBasedEncounters
	end	

Route34_MapScript_EggReady::
	setobjectxyperm LOCALID_ROUTE34_DAYCAREMAN, 30, 34
	return

Route34_EventScript_YoungsterSamuel::
	trainerbattle_single TRAINER_SAMUEL Route34_Text_YoungsterSamuel_Seen, Route34_Text_YoungsterSamuel_Beaten
	msgbox Route34_Text_YoungsterSamuel_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_IAN Route34_Text_YoungsterIan_Seen, Route34_Text_YoungsterIan_Beaten
	msgbox Route34_Text_YoungsterIan_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CamperTodd::
	trainerbattle_single TRAINER_TODD Route34_Text_CamperTodd_Seen, Route34_Text_CamperTodd_Beaten
	msgbox Route34_Text_CamperTodd_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_PicnickerGina::
	trainerbattle_single TRAINER_GINA Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	trainerbattle_single TRAINER_KEITH Route34_Text_OfficerKeith_Seen, Route34_Text_OfficerKeith_Win
	msgbox Route34_Text_OfficerKeith_After, MSGBOX_AUTOCLOSE
	end


Route34_EventScript_PokefanMBrandon::
	trainerbattle_single TRAINER_BRANDON Route34_Text_PokefanBrandon_Seen, Route34_Text_PokefanBrandon_Beaten
	msgbox Route34_Text_PokefanBrandon_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE Route34_Text_CooltrainerIrene_Seen, Route34_Text_CooltrainerIrene_Beaten
	msgbox Route34_Text_CooltrainerIrene_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Jenn::
	trainerbattle_single TRAINER_JENN Route34_Text_CooltrainerJenn_Seen, Route34_Text_CooltrainerJenn_Beaten
	msgbox Route34_Text_CooltrainerJenn_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Kate::
	trainerbattle_single TRAINER_KATE Route34_Text_CooltrainerKate_Seen, Route34_Text_CooltrainerKate_Beaten
	msgbox Route34_Text_CooltrainerKate_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign1::
	lock
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign2::
	lock
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign3::
	lock
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Item_SoftSand::
	finditem ITEM_SOFT_SAND
	end

Route34_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

Route34_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end


Route34_Text_YoungsterSamuel_Seen:
	.string "Hé ! Je cherche FÉROSINGE !$"

Route34_Text_YoungsterSamuel_Beaten:
	.string "Battu par un inconnu de passage !$"

Route34_Text_YoungsterSamuel_After:
	.string "Je vais m'entraîner encore plus dur.\p"
	.string "Après tout, j'essaie de devenir\n"
	.string "un CHAMPION d'ARÈNE.$"

Route34_Text_YoungsterIan_Seen:
	.string "Je suis le meilleur de ma classe\n"
	.string "aux POKéMON.$"

Route34_Text_YoungsterIan_Beaten:
	.string "Non ! Il y a de meilleurs dresseurs…$"

Route34_Text_YoungsterIan_After:
	.string "Je fais de mon mieux pour devenir\n"
	.string "la star de ma classe.$"

Route34_Text_CamperTodd_Seen:
	.string "J'ai confiance en ma capacité à\n"
	.string "élever des POKéMON.\p"
	.string "Tu veux voir ?$"

Route34_Text_CamperTodd_Beaten:
	.string "J'ai mal préparé mon entraînement ?$"

Route34_Text_CamperTodd_After:
	.string "Je devrais peut-être en laisser un à la PENSION,\n"
	.string "ou utiliser des objets…$"

Route34_Text_PicnickerGina_Seen:
	.string "Tu es un DRESSEUR ?\p"
	.string "Faisons un combat d'entraînement.$"

Route34_Text_PicnickerGina_Beaten:
	.string "Oh, non ! Je n'arrive pas à gagner…$"

Route34_Text_PicnickerGina_After:
	.string "Tu es trop fort pour être un\n"
	.string "partenaire d'entraînement.$"

Route34_Text_OfficerKeith_Seen:
	.string "Qui va là ?\n"
	.string "Qu'est-ce que tu fabriques ?$"

Route34_Text_OfficerKeith_Win:
	.string "Tu es un gamin coriace.$"

Route34_Text_OfficerKeith_After:
	.string "Oui, rien de mal aujourd'hui.\p"
	.string "Sois sage et ne cherche pas d'ennuis.$"

Route34_Text_OfficerKeith_Daytime:
	.string "Je suis en patrouille pour repérer\n"
	.string "des individus suspects.$"

Route34_Text_PokefanBrandon_Seen:
	.string "Je viens de récupérer mon POKéMON de la\n"
	.string "PENSION.\p"
	.string "Voyons combien il est devenu plus fort !$"

Route34_Text_PokefanBrandon_Beaten:
	.string "Pourquoi ça finit comme ça ?$"

Route34_Text_PokefanBrandon_After:
	.string "Mon POKéMON est revenu avec de nouvelles capacités.\p"
	.string "Ça m'a complètement déconcerté !$"

Route34_Text_Sign_IlexForest:
	.string "FORÊT DE ILEX\n"
	.string "PAR LA PORTE$"

Route34_Text_Sign_Route34:
	.string "ROUTE 34\n"
	.string "DOUBLONVILLE - ECORCIA\p"
	.string "FORÊT DE ILEX QUELQUE PART ENTRE$"

Route34_Text_TrainerTips:
	.string "CONSEILS AUX DRESSEURS\p"
	.string "Les BAIES poussent plusieurs fois par jour\n"
	.string "sur les arbres.\p"
	.string "Notez quels arbres portent\n"
	.string "quelles BAIES.$"

Route34_Text_CooltrainerIrene_Seen:
	.string "IRENE : Qui es-tu ?!$"

Route34_Text_CooltrainerIrene_Beaten:
	.string "IRENE : Ohhh ! Tu es trop fort !$"

Route34_Text_CooltrainerIrene_After1:
	.string "IRENE : Ma soeur KATE va t'avoir\n"
	.string "pour ça !$"

Route34_Text_CooltrainerIrene_After2:
	.string "IRENE : Cette plage n'est pas géniale ?\p"
	.string "C'est notre petit coin secret !$"

Route34_Text_CooltrainerJenn_Seen:
	.string "JENN : Quoi… ?\n"
	.string "Qu'est-ce que tu fais ?$"

Route34_Text_CooltrainerJenn_Beaten:
	.string "JENN : Désolée, IRENE ! Ma chère soeur !$"

Route34_Text_CooltrainerJenn_After1:
	.string "JENN : Ne te laisse pas aller ! Ma soeur\n"
	.string "KATE est costaude !$"

Route34_Text_CooltrainerJenn_After2:
	.string "JENN : La lumière du soleil rend\n"
	.string "ton corps plus fort.$"

Route34_Text_CooltrainerKate_Seen:
	.string "KATE : Je dois te remercier de\n"
	.string "t'avoir occupé de mes soeurs !$"

Route34_Text_CooltrainerKate_Beaten:
	.string "KATE : Non ! Je n'arrive pas à croire que j'ai perdu.$"

Route34_Text_CooltrainerKate_GiveSoftSand:
	.string "KATE : Tu es si fort.\n"
	.string "On a perdu sans excuse…\p"
	.string "Tiens, prends ça !$"

Route34_Text_CooltrainerKate_After:
	.string "KATE : Désolée de t'avoir sauté dessus.\p"
	.string "On ne s'attendait pas à ce que quelqu'un nous\n"
	.string "trouve ici. Tu nous as bien fait sursauter.$"


Route34_Text_Sign_DayCare:
	.string "POKéMON PENSION\p"
	.string "CONFIEZ-NOUS VOS POKéMON !$"
