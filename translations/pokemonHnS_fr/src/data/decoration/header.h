const struct Decoration gDecorations[] =
{
    [DECOR_NONE] =
    {
        .id = DECOR_NONE,
        .name = _("PETIT BUREAU"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DESK,
        .price = 0,
        .description = DecorDesc_SMALL_DESK,
        .tiles = DecorGfx_SMALL_DESK,
    },

    [DECOR_SMALL_DESK] =
    {
        .id = DECOR_SMALL_DESK,
        .name = _("PETIT BUREAU"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DESK,
        .price = 3000,
        .description = DecorDesc_SMALL_DESK,
        .tiles = DecorGfx_SMALL_DESK,
    },

    [DECOR_POKEMON_DESK] =
    {
        .id = DECOR_POKEMON_DESK,
        .name = _("BUREAU POKéMON"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DESK,
        .price = 3000,
        .description = DecorDesc_POKEMON_DESK,
        .tiles = DecorGfx_POKEMON_DESK,
    },

    [DECOR_HEAVY_DESK] =
    {
        .id = DECOR_HEAVY_DESK,
        .name = _("LOURD BUREAU"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x2,
        .category = DECORCAT_DESK,
        .price = 6000,
        .description = DecorDesc_HEAVY_DESK,
        .tiles = DecorGfx_HEAVY_DESK,
    },

    [DECOR_RAGGED_DESK] =
    {
        .id = DECOR_RAGGED_DESK,
        .name = _("VIEUX BUREAU"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x2,
        .category = DECORCAT_DESK,
        .price = 6000,
        .description = DecorDesc_RAGGED_DESK,
        .tiles = DecorGfx_RAGGED_DESK,
    },

    [DECOR_COMFORT_DESK] =
    {
        .id = DECOR_COMFORT_DESK,
        .name = _("BUREAU CONFORT"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x2,
        .category = DECORCAT_DESK,
        .price = 6000,
        .description = DecorDesc_COMFORT_DESK,
        .tiles = DecorGfx_COMFORT_DESK,
    },

    [DECOR_PRETTY_DESK] =
    {
        .id = DECOR_PRETTY_DESK,
        .name = _("JOLI BUREAU"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = DecorDesc_PRETTY_DESK,
        .tiles = DecorGfx_PRETTY_DESK,
    },

    [DECOR_BRICK_DESK] =
    {
        .id = DECOR_BRICK_DESK,
        .name = _("BUREAU BRIQUE"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = DecorDesc_BRICK_DESK,
        .tiles = DecorGfx_BRICK_DESK,
    },

    [DECOR_CAMP_DESK] =
    {
        .id = DECOR_CAMP_DESK,
        .name = _("BUREAU CAMPING"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = DecorDesc_CAMP_DESK,
        .tiles = DecorGfx_CAMP_DESK,
    },

    [DECOR_HARD_DESK] =
    {
        .id = DECOR_HARD_DESK,
        .name = _("DUR BUREAU"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = DecorDesc_HARD_DESK,
        .tiles = DecorGfx_HARD_DESK,
    },

    [DECOR_SMALL_CHAIR] =
    {
        .id = DECOR_SMALL_CHAIR,
        .name = _("PETITE CHAISE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_SMALL_CHAIR,
        .tiles = DecorGfx_SMALL_CHAIR,
    },

    [DECOR_POKEMON_CHAIR] =
    {
        .id = DECOR_POKEMON_CHAIR,
        .name = _("FAUTEUIL POKéMON"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_POKEMON_CHAIR,
        .tiles = DecorGfx_POKEMON_CHAIR,
    },

    [DECOR_HEAVY_CHAIR] =
    {
        .id = DECOR_HEAVY_CHAIR,
        .name = _("FAUTEUIL LOURD"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_HEAVY_CHAIR,
        .tiles = DecorGfx_HEAVY_CHAIR,
    },

    [DECOR_PRETTY_CHAIR] =
    {
        .id = DECOR_PRETTY_CHAIR,
        .name = _("FAUTEUIL JOLI"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_PRETTY_CHAIR,
        .tiles = DecorGfx_PRETTY_CHAIR,
    },

    [DECOR_COMFORT_CHAIR] =
    {
        .id = DECOR_COMFORT_CHAIR,
        .name = _("FAUTEUIL CONFORT"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_COMFORT_CHAIR,
        .tiles = DecorGfx_COMFORT_CHAIR,
    },

    [DECOR_RAGGED_CHAIR] =
    {
        .id = DECOR_RAGGED_CHAIR,
        .name = _("FAUTEUIL VIEUX"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_RAGGED_CHAIR,
        .tiles = DecorGfx_RAGGED_CHAIR,
    },

    [DECOR_BRICK_CHAIR] =
    {
        .id = DECOR_BRICK_CHAIR,
        .name = _("FAUTEUIL BRIQUE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_BRICK_CHAIR,
        .tiles = DecorGfx_BRICK_CHAIR,
    },

    [DECOR_CAMP_CHAIR] =
    {
        .id = DECOR_CAMP_CHAIR,
        .name = _("CHAISE CAMPING"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_CAMP_CHAIR,
        .tiles = DecorGfx_CAMP_CHAIR,
    },

    [DECOR_HARD_CHAIR] =
    {
        .id = DECOR_HARD_CHAIR,
        .name = _("DURE CHAISE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_HARD_CHAIR,
        .tiles = DecorGfx_HARD_CHAIR,
    },

    [DECOR_RED_PLANT] =
    {
        .id = DECOR_RED_PLANT,
        .name = _("PLANTE ROUGE"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_PLANT,
        .price = 3000,
        .description = DecorDesc_RED_PLANT,
        .tiles = DecorGfx_RED_PLANT,
    },

    [DECOR_TROPICAL_PLANT] =
    {
        .id = DECOR_TROPICAL_PLANT,
        .name = _("PLANTE TROPICALE"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_PLANT,
        .price = 3000,
        .description = DecorDesc_TROPICAL_PLANT,
        .tiles = DecorGfx_TROPICAL_PLANT,
    },

    [DECOR_PRETTY_FLOWERS] =
    {
        .id = DECOR_PRETTY_FLOWERS,
        .name = _("JOLIES FLEURS"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_PLANT,
        .price = 3000,
        .description = DecorDesc_PRETTY_FLOWERS,
        .tiles = DecorGfx_PRETTY_FLOWERS,
    },

    [DECOR_COLORFUL_PLANT] =
    {
        .id = DECOR_COLORFUL_PLANT,
        .name = _("PLANTE COLORÉE"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_PLANT,
        .price = 5000,
        .description = DecorDesc_COLORFUL_PLANT,
        .tiles = DecorGfx_COLORFUL_PLANT,
    },

    [DECOR_BIG_PLANT] =
    {
        .id = DECOR_BIG_PLANT,
        .name = _("GRANDE PLANTE"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_PLANT,
        .price = 5000,
        .description = DecorDesc_BIG_PLANT,
        .tiles = DecorGfx_BIG_PLANT,
    },

    [DECOR_GORGEOUS_PLANT] =
    {
        .id = DECOR_GORGEOUS_PLANT,
        .name = _("PLANTE SUPERBE"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_PLANT,
        .price = 5000,
        .description = DecorDesc_GORGEOUS_PLANT,
        .tiles = DecorGfx_GORGEOUS_PLANT,
    },

    [DECOR_RED_BRICK] =
    {
        .id = DECOR_RED_BRICK,
        .name = _("BRIQUE ROUGE"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_RED_BRICK,
        .tiles = DecorGfx_RED_BRICK,
    },

    [DECOR_YELLOW_BRICK] =
    {
        .id = DECOR_YELLOW_BRICK,
        .name = _("BRIQUE JAUNE"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_YELLOW_BRICK,
        .tiles = DecorGfx_YELLOW_BRICK,
    },

    [DECOR_BLUE_BRICK] =
    {
        .id = DECOR_BLUE_BRICK,
        .name = _("BRIQUE BLEUE"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_BLUE_BRICK,
        .tiles = DecorGfx_BLUE_BRICK,
    },

    [DECOR_RED_BALLOON] =
    {
        .id = DECOR_RED_BALLOON,
        .name = _("BALLON ROUGE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_RED_BALLOON,
        .tiles = DecorGfx_RED_BALLOON,
    },

    [DECOR_BLUE_BALLOON] =
    {
        .id = DECOR_BLUE_BALLOON,
        .name = _("BALLON BLEU"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_BLUE_BALLOON,
        .tiles = DecorGfx_BLUE_BALLOON,
    },

    [DECOR_YELLOW_BALLOON] =
    {
        .id = DECOR_YELLOW_BALLOON,
        .name = _("BALLON JAUNE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_YELLOW_BALLOON,
        .tiles = DecorGfx_YELLOW_BALLOON,
    },

    [DECOR_RED_TENT] =
    {
        .id = DECOR_RED_TENT,
        .name = _("TENTE ROUGE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_ORNAMENT,
        .price = 10000,
        .description = DecorDesc_RED_TENT,
        .tiles = DecorGfx_RED_TENT,
    },

    [DECOR_BLUE_TENT] =
    {
        .id = DECOR_BLUE_TENT,
        .name = _("TENTE BLEUE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_ORNAMENT,
        .price = 10000,
        .description = DecorDesc_BLUE_TENT,
        .tiles = DecorGfx_BLUE_TENT,
    },

    [DECOR_SOLID_BOARD] =
    {
        .id = DECOR_SOLID_BOARD,
        .name = _("PLANCHE SOLIDE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = DecorDesc_SOLID_BOARD,
        .tiles = DecorGfx_SOLID_BOARD,
    },

    [DECOR_SLIDE] =
    {
        .id = DECOR_SLIDE,
        .name = _("GLISSE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_2x4,
        .category = DECORCAT_ORNAMENT,
        .price = 8000,
        .description = DecorDesc_SLIDE,
        .tiles = DecorGfx_SLIDE,
    },

    [DECOR_FENCE_LENGTH] =
    {
        .id = DECOR_FENCE_LENGTH,
        .name = _("LONGUEUR CLÔTURE"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_FENCE_LENGTH,
        .tiles = DecorGfx_FENCE_LENGTH,
    },

    [DECOR_FENCE_WIDTH] =
    {
        .id = DECOR_FENCE_WIDTH,
        .name = _("LARGEUR CLÔTURE"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_FENCE_WIDTH,
        .tiles = DecorGfx_FENCE_WIDTH,
    },

    [DECOR_TIRE] =
    {
        .id = DECOR_TIRE,
        .name = _("PNEU"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_ORNAMENT,
        .price = 800,
        .description = DecorDesc_TIRE,
        .tiles = DecorGfx_TIRE,
    },

    [DECOR_STAND] =
    {
        .id = DECOR_STAND,
        .name = _("SUPPORT"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_4x2,
        .category = DECORCAT_ORNAMENT,
        .price = 7000,
        .description = DecorDesc_STAND,
        .tiles = DecorGfx_STAND,
    },

    [DECOR_MUD_BALL] =
    {
        .id = DECOR_MUD_BALL,
        .name = _("BOULE BOUE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 200,
        .description = DecorDesc_MUD_BALL,
        .tiles = DecorGfx_MUD_BALL,
    },

    [DECOR_BREAKABLE_DOOR] =
    {
        .id = DECOR_BREAKABLE_DOOR,
        .name = _("PORTE FRAGILE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = DecorDesc_BREAKABLE_DOOR,
        .tiles = DecorGfx_BREAKABLE_DOOR,
    },

    [DECOR_SAND_ORNAMENT] =
    {
        .id = DECOR_SAND_ORNAMENT,
        .name = _("ORNAMENT DE SABLE"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = DecorDesc_SAND_ORNAMENT,
        .tiles = DecorGfx_SAND_ORNAMENT,
    },

    [DECOR_SILVER_SHIELD] =
    {
        .id = DECOR_SILVER_SHIELD,
        .name = _("BOUCLIER ARGENT"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 0,
        .description = DecorDesc_SILVER_SHIELD,
        .tiles = DecorGfx_SILVER_SHIELD,
    },

    [DECOR_GOLD_SHIELD] =
    {
        .id = DECOR_GOLD_SHIELD,
        .name = _("BOUCLIER OR"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 0,
        .description = DecorDesc_GOLD_SHIELD,
        .tiles = DecorGfx_GOLD_SHIELD,
    },

    [DECOR_GLASS_ORNAMENT] =
    {
        .id = DECOR_GLASS_ORNAMENT,
        .name = _("ORNAMENT DE VERRE"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 0,
        .description = DecorDesc_GLASS_ORNAMENT,
        .tiles = DecorGfx_GLASS_ORNAMENT,
    },

    [DECOR_TV] =
    {
        .id = DECOR_TV,
        .name = _("TV"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = DecorDesc_TV,
        .tiles = DecorGfx_TV,
    },

    [DECOR_ROUND_TV] =
    {
        .id = DECOR_ROUND_TV,
        .name = _("TV RONDE"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 4000,
        .description = DecorDesc_ROUND_TV,
        .tiles = DecorGfx_ROUND_TV,
    },

    [DECOR_CUTE_TV] =
    {
        .id = DECOR_CUTE_TV,
        .name = _("TV MIGNON"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 4000,
        .description = DecorDesc_CUTE_TV,
        .tiles = DecorGfx_CUTE_TV,
    },

    [DECOR_GLITTER_MAT] =
    {
        .id = DECOR_GLITTER_MAT,
        .name = _("TAPIS BRILLANT"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 2000,
        .description = DecorDesc_GLITTER_MAT,
        .tiles = DecorGfx_GLITTER_MAT,
    },

    [DECOR_JUMP_MAT] =
    {
        .id = DECOR_JUMP_MAT,
        .name = _("TAPIS SAUT"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 2000,
        .description = DecorDesc_JUMP_MAT,
        .tiles = DecorGfx_JUMP_MAT,
    },

    [DECOR_SPIN_MAT] =
    {
        .id = DECOR_SPIN_MAT,
        .name = _("TAPIS TOUR"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 2000,
        .description = DecorDesc_SPIN_MAT,
        .tiles = DecorGfx_SPIN_MAT,
    },

    [DECOR_C_LOW_NOTE_MAT] =
    {
        .id = DECOR_C_LOW_NOTE_MAT,
        .name = _("TAPIS NOTE DO BAS"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_C_LOW_NOTE_MAT,
        .tiles = DecorGfx_C_LOW_NOTE_MAT,
    },

    [DECOR_D_NOTE_MAT] =
    {
        .id = DECOR_D_NOTE_MAT,
        .name = _("TAPIS NOTE RÉ"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_D_NOTE_MAT,
        .tiles = DecorGfx_D_NOTE_MAT,
    },

    [DECOR_E_NOTE_MAT] =
    {
        .id = DECOR_E_NOTE_MAT,
        .name = _("TAPIS NOTE MI"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_E_NOTE_MAT,
        .tiles = DecorGfx_E_NOTE_MAT,
    },

    [DECOR_F_NOTE_MAT] =
    {
        .id = DECOR_F_NOTE_MAT,
        .name = _("TAPIS NOTE FA"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_F_NOTE_MAT,
        .tiles = DecorGfx_F_NOTE_MAT,
    },

    [DECOR_G_NOTE_MAT] =
    {
        .id = DECOR_G_NOTE_MAT,
        .name = _("TAPIS NOTE SOL"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_G_NOTE_MAT,
        .tiles = DecorGfx_G_NOTE_MAT,
    },

    [DECOR_A_NOTE_MAT] =
    {
        .id = DECOR_A_NOTE_MAT,
        .name = _("TAPIS NOTE LA"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_A_NOTE_MAT,
        .tiles = DecorGfx_A_NOTE_MAT,
    },

    [DECOR_B_NOTE_MAT] =
    {
        .id = DECOR_B_NOTE_MAT,
        .name = _("TAPIS NOTE SI"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_B_NOTE_MAT,
        .tiles = DecorGfx_B_NOTE_MAT,
    },

    [DECOR_C_HIGH_NOTE_MAT] =
    {
        .id = DECOR_C_HIGH_NOTE_MAT,
        .name = _("TAPIS NOTE DO HAI"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_C_HIGH_NOTE_MAT,
        .tiles = DecorGfx_C_HIGH_NOTE_MAT,
    },

    [DECOR_SURF_MAT] =
    {
        .id = DECOR_SURF_MAT,
        .name = _("TAPIS SURF"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = DecorDesc_SURF_MAT,
        .tiles = DecorGfx_SURF_MAT,
    },

    [DECOR_THUNDER_MAT] =
    {
        .id = DECOR_THUNDER_MAT,
        .name = _("TAPIS FOUDRE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = DecorDesc_THUNDER_MAT,
        .tiles = DecorGfx_THUNDER_MAT,
    },

    [DECOR_FIRE_BLAST_MAT] =
    {
        .id = DECOR_FIRE_BLAST_MAT,
        .name = _("TAPIS DÉFLAGRATION"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = DecorDesc_FIRE_BLAST_MAT,
        .tiles = DecorGfx_FIRE_BLAST_MAT,
    },

    [DECOR_POWDER_SNOW_MAT] =
    {
        .id = DECOR_POWDER_SNOW_MAT,
        .name = _("TAPIS POUDREUSE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = DecorDesc_POWDER_SNOW_MAT,
        .tiles = DecorGfx_POWDER_SNOW_MAT,
    },

    [DECOR_ATTRACT_MAT] =
    {
        .id = DECOR_ATTRACT_MAT,
        .name = _("TAPIS ATTRACTION"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = DecorDesc_ATTRACT_MAT,
        .tiles = DecorGfx_ATTRACT_MAT,
    },

    [DECOR_FISSURE_MAT] =
    {
        .id = DECOR_FISSURE_MAT,
        .name = _("TAPIS ABÎME"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = DecorDesc_FISSURE_MAT,
        .tiles = DecorGfx_FISSURE_MAT,
    },

    [DECOR_SPIKES_MAT] =
    {
        .id = DECOR_SPIKES_MAT,
        .name = _("TAPIS PICOTS"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = DecorDesc_SPIKES_MAT,
        .tiles = DecorGfx_SPIKES_MAT,
    },

    [DECOR_BALL_POSTER] =
    {
        .id = DECOR_BALL_POSTER,
        .name = _("POSTER BALL"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = DecorDesc_BALL_POSTER,
        .tiles = DecorGfx_BALL_POSTER,
    },

    [DECOR_GREEN_POSTER] =
    {
        .id = DECOR_GREEN_POSTER,
        .name = _("POSTER VERT"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = DecorDesc_GREEN_POSTER,
        .tiles = DecorGfx_GREEN_POSTER,
    },

    [DECOR_RED_POSTER] =
    {
        .id = DECOR_RED_POSTER,
        .name = _("AFFICHE ROUGE"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = DecorDesc_RED_POSTER,
        .tiles = DecorGfx_RED_POSTER,
    },

    [DECOR_BLUE_POSTER] =
    {
        .id = DECOR_BLUE_POSTER,
        .name = _("POSTER BLEU"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = DecorDesc_BLUE_POSTER,
        .tiles = DecorGfx_BLUE_POSTER,
    },

    [DECOR_CUTE_POSTER] =
    {
        .id = DECOR_CUTE_POSTER,
        .name = _("POSTER MIMINE"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = DecorDesc_CUTE_POSTER,
        .tiles = DecorGfx_CUTE_POSTER,
    },

    [DECOR_PIKA_POSTER] =
    {
        .id = DECOR_PIKA_POSTER,
        .name = _("AFFICHE PIKA"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = DecorDesc_PIKA_POSTER,
        .tiles = DecorGfx_PIKA_POSTER,
    },

    [DECOR_LONG_POSTER] =
    {
        .id = DECOR_LONG_POSTER,
        .name = _("POSTER LONG"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = DecorDesc_LONG_POSTER,
        .tiles = DecorGfx_LONG_POSTER,
    },

    [DECOR_SEA_POSTER] =
    {
        .id = DECOR_SEA_POSTER,
        .name = _("AFFICHE MER"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = DecorDesc_SEA_POSTER,
        .tiles = DecorGfx_SEA_POSTER,
    },

    [DECOR_SKY_POSTER] =
    {
        .id = DECOR_SKY_POSTER,
        .name = _("AFFICHE CIEL"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = DecorDesc_SKY_POSTER,
        .tiles = DecorGfx_SKY_POSTER,
    },

    [DECOR_KISS_POSTER] =
    {
        .id = DECOR_KISS_POSTER,
        .name = _("POSTER BAISER"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = DecorDesc_KISS_POSTER,
        .tiles = DecorGfx_KISS_POSTER,
    },

    [DECOR_PICHU_DOLL] =
    {
        .id = DECOR_PICHU_DOLL,
        .name = _("POUPEE PICHU"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_PICHU_DOLL,
        .tiles = DecorGfx_PICHU_DOLL,
    },

    [DECOR_PIKACHU_DOLL] =
    {
        .id = DECOR_PIKACHU_DOLL,
        .name = _("POUPÉE PIKACHU"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_PIKACHU_DOLL,
        .tiles = DecorGfx_PIKACHU_DOLL,
    },

    [DECOR_MARILL_DOLL] =
    {
        .id = DECOR_MARILL_DOLL,
        .name = _("POUPÉE MARILL"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_MARILL_DOLL,
        .tiles = DecorGfx_MARILL_DOLL,
    },

    [DECOR_TOGEPI_DOLL] =
    {
        .id = DECOR_TOGEPI_DOLL,
        .name = _("POUPEE TOGEPI"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_TOGEPI_DOLL,
        .tiles = DecorGfx_TOGEPI_DOLL,
    },

    [DECOR_CYNDAQUIL_DOLL] =
    {
        .id = DECOR_CYNDAQUIL_DOLL,
        .name = _("POUPÉE HÉRICENDRE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_CYNDAQUIL_DOLL,
        .tiles = DecorGfx_CYNDAQUIL_DOLL,
    },

    [DECOR_CHIKORITA_DOLL] =
    {
        .id = DECOR_CHIKORITA_DOLL,
        .name = _("POUPÉE GERMIGNON"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_CHIKORITA_DOLL,
        .tiles = DecorGfx_CHIKORITA_DOLL,
    },

    [DECOR_TOTODILE_DOLL] =
    {
        .id = DECOR_TOTODILE_DOLL,
        .name = _("POUPÉE KAIMINUS"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_TOTODILE_DOLL,
        .tiles = DecorGfx_TOTODILE_DOLL,
    },

    [DECOR_JIGGLYPUFF_DOLL] =
    {
        .id = DECOR_JIGGLYPUFF_DOLL,
        .name = _("POUPÉE RONDOUDOU"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_JIGGLYPUFF_DOLL,
        .tiles = DecorGfx_JIGGLYPUFF_DOLL,
    },

    [DECOR_MEOWTH_DOLL] =
    {
        .id = DECOR_MEOWTH_DOLL,
        .name = _("POUPÉE MIAOUSS"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_MEOWTH_DOLL,
        .tiles = DecorGfx_MEOWTH_DOLL,
    },

    [DECOR_CLEFAIRY_DOLL] =
    {
        .id = DECOR_CLEFAIRY_DOLL,
        .name = _("POUPÉE MÉLOFÉE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_CLEFAIRY_DOLL,
        .tiles = DecorGfx_CLEFAIRY_DOLL,
    },

    [DECOR_DITTO_DOLL] =
    {
        .id = DECOR_DITTO_DOLL,
        .name = _("POUPEE METAMORPH"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_DITTO_DOLL,
        .tiles = DecorGfx_DITTO_DOLL,
    },

    [DECOR_SMOOCHUM_DOLL] =
    {
        .id = DECOR_SMOOCHUM_DOLL,
        .name = _("POUPÉE LIPPOUTI"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_SMOOCHUM_DOLL,
        .tiles = DecorGfx_SMOOCHUM_DOLL,
    },

    [DECOR_TREECKO_DOLL] =
    {
        .id = DECOR_TREECKO_DOLL,
        .name = _("POUPÉE ARBOKO"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_TREECKO_DOLL,
        .tiles = DecorGfx_TREECKO_DOLL,
    },

    [DECOR_TORCHIC_DOLL] =
    {
        .id = DECOR_TORCHIC_DOLL,
        .name = _("POUPÉE POUSSIFEU"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_TORCHIC_DOLL,
        .tiles = DecorGfx_TORCHIC_DOLL,
    },

    [DECOR_MUDKIP_DOLL] =
    {
        .id = DECOR_MUDKIP_DOLL,
        .name = _("POUPÉE GOBOU"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_MUDKIP_DOLL,
        .tiles = DecorGfx_MUDKIP_DOLL,
    },

    [DECOR_DUSKULL_DOLL] =
    {
        .id = DECOR_DUSKULL_DOLL,
        .name = _("POUPÉE SKELENOX"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_DUSKULL_DOLL,
        .tiles = DecorGfx_DUSKULL_DOLL,
    },

    [DECOR_WYNAUT_DOLL] =
    {
        .id = DECOR_WYNAUT_DOLL,
        .name = _("POUPEE POIHMA"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_WYNAUT_DOLL,
        .tiles = DecorGfx_WYNAUT_DOLL,
    },

    [DECOR_BALTOY_DOLL] =
    {
        .id = DECOR_BALTOY_DOLL,
        .name = _("POUPÉE BALTOY"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_BALTOY_DOLL,
        .tiles = DecorGfx_BALTOY_DOLL,
    },

    [DECOR_KECLEON_DOLL] =
    {
        .id = DECOR_KECLEON_DOLL,
        .name = _("POUPÉE KECLEON"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_KECLEON_DOLL,
        .tiles = DecorGfx_KECLEON_DOLL,
    },

    [DECOR_AZURILL_DOLL] =
    {
        .id = DECOR_AZURILL_DOLL,
        .name = _("POUPÉE AZURILL"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_AZURILL_DOLL,
        .tiles = DecorGfx_AZURILL_DOLL,
    },

    [DECOR_SKITTY_DOLL] =
    {
        .id = DECOR_SKITTY_DOLL,
        .name = _("POUPEE SKITTY"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_SKITTY_DOLL,
        .tiles = DecorGfx_SKITTY_DOLL,
    },

    [DECOR_SWABLU_DOLL] =
    {
        .id = DECOR_SWABLU_DOLL,
        .name = _("POUPEE SWABLU"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_SWABLU_DOLL,
        .tiles = DecorGfx_SWABLU_DOLL,
    },

    [DECOR_GULPIN_DOLL] =
    {
        .id = DECOR_GULPIN_DOLL,
        .name = _("POUPÉE GLUPI"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_GULPIN_DOLL,
        .tiles = DecorGfx_GULPIN_DOLL,
    },

    [DECOR_LOTAD_DOLL] =
    {
        .id = DECOR_LOTAD_DOLL,
        .name = _("POUPEE NENUPLOT"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_LOTAD_DOLL,
        .tiles = DecorGfx_LOTAD_DOLL,
    },

    [DECOR_SEEDOT_DOLL] =
    {
        .id = DECOR_SEEDOT_DOLL,
        .name = _("POUPEE GRAINIPIOT"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_SEEDOT_DOLL,
        .tiles = DecorGfx_SEEDOT_DOLL,
    },

    [DECOR_PIKA_CUSHION] =
    {
        .id = DECOR_PIKA_CUSHION,
        .name = _("COUSSIN PIKA"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_PIKA_CUSHION,
        .tiles = DecorGfx_PIKA_CUSHION,
    },

    [DECOR_ROUND_CUSHION] =
    {
        .id = DECOR_ROUND_CUSHION,
        .name = _("COUSSIN ROND"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_ROUND_CUSHION,
        .tiles = DecorGfx_ROUND_CUSHION,
    },

    [DECOR_KISS_CUSHION] =
    {
        .id = DECOR_KISS_CUSHION,
        .name = _("COUSSIN BAISER"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_KISS_CUSHION,
        .tiles = DecorGfx_KISS_CUSHION,
    },

    [DECOR_ZIGZAG_CUSHION] =
    {
        .id = DECOR_ZIGZAG_CUSHION,
        .name = _("COUSSIN ZIGZAG"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_ZIGZAG_CUSHION,
        .tiles = DecorGfx_ZIGZAG_CUSHION,
    },

    [DECOR_SPIN_CUSHION] =
    {
        .id = DECOR_SPIN_CUSHION,
        .name = _("COUSSIN TOURNANT"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_SPIN_CUSHION,
        .tiles = DecorGfx_SPIN_CUSHION,
    },

    [DECOR_DIAMOND_CUSHION] =
    {
        .id = DECOR_DIAMOND_CUSHION,
        .name = _("COUSSIN DIAMANT"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_DIAMOND_CUSHION,
        .tiles = DecorGfx_DIAMOND_CUSHION,
    },

    [DECOR_BALL_CUSHION] =
    {
        .id = DECOR_BALL_CUSHION,
        .name = _("COUSSIN BALL"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_BALL_CUSHION,
        .tiles = DecorGfx_BALL_CUSHION,
    },

    [DECOR_GRASS_CUSHION] =
    {
        .id = DECOR_GRASS_CUSHION,
        .name = _("COUSSIN PLANTE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_GRASS_CUSHION,
        .tiles = DecorGfx_GRASS_CUSHION,
    },

    [DECOR_FIRE_CUSHION] =
    {
        .id = DECOR_FIRE_CUSHION,
        .name = _("COUSSIN FEU"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_FIRE_CUSHION,
        .tiles = DecorGfx_FIRE_CUSHION,
    },

    [DECOR_WATER_CUSHION] =
    {
        .id = DECOR_WATER_CUSHION,
        .name = _("COUSSIN EAU"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_WATER_CUSHION,
        .tiles = DecorGfx_WATER_CUSHION,
    },

    [DECOR_SNORLAX_DOLL] =
    {
        .id = DECOR_SNORLAX_DOLL,
        .name = _("POUPÉE RONFLEX"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_SNORLAX_DOLL,
        .tiles = DecorGfx_SNORLAX_DOLL,
    },

    [DECOR_RHYDON_DOLL] =
    {
        .id = DECOR_RHYDON_DOLL,
        .name = _("POUPEE RHINOFEROS"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_RHYDON_DOLL,
        .tiles = DecorGfx_RHYDON_DOLL,
    },

    [DECOR_LAPRAS_DOLL] =
    {
        .id = DECOR_LAPRAS_DOLL,
        .name = _("POUPÉE LOKHLASS"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_LAPRAS_DOLL,
        .tiles = DecorGfx_LAPRAS_DOLL,
    },

    [DECOR_VENUSAUR_DOLL] =
    {
        .id = DECOR_VENUSAUR_DOLL,
        .name = _("POUPÉE FLORIZARRE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_VENUSAUR_DOLL,
        .tiles = DecorGfx_VENUSAUR_DOLL,
    },

    [DECOR_CHARIZARD_DOLL] =
    {
        .id = DECOR_CHARIZARD_DOLL,
        .name = _("POUPÉE DRACAUFEU"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_CHARIZARD_DOLL,
        .tiles = DecorGfx_CHARIZARD_DOLL,
    },

    [DECOR_BLASTOISE_DOLL] =
    {
        .id = DECOR_BLASTOISE_DOLL,
        .name = _("POUPÉE TORTANK"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_BLASTOISE_DOLL,
        .tiles = DecorGfx_BLASTOISE_DOLL,
    },

    [DECOR_WAILMER_DOLL] =
    {
        .id = DECOR_WAILMER_DOLL,
        .name = _("POUPÉE WAILMER"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_WAILMER_DOLL,
        .tiles = DecorGfx_WAILMER_DOLL,
    },
    
    [DECOR_REGIROCK_DOLL] =
    {
        .id = DECOR_REGIROCK_DOLL,
        .name = _("POUPÉE REGIROCK"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_REGIROCK_DOLL,
        .tiles = DecorGfx_REGIROCK_DOLL,
    },

    [DECOR_REGICE_DOLL] =
    {
        .id = DECOR_REGICE_DOLL,
        .name = _("POUPEE REGICE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_REGICE_DOLL,
        .tiles = DecorGfx_REGICE_DOLL,
    },

    [DECOR_REGISTEEL_DOLL] =
    {
        .id = DECOR_REGISTEEL_DOLL,
        .name = _("POUPÉE REGISTEL"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_REGISTEEL_DOLL,
        .tiles = DecorGfx_REGISTEEL_DOLL,
    }
};
