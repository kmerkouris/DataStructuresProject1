#include "raylib.h"

#include <state.h>
#include <interface.h>



//ASSETS

Texture jet_img;
Texture warship_img;
Texture heli_img;
Sound game_over_snd;
Sound BAckround_snd;

void interface_init() {
	// Αρχικοποίηση του παραθύρου
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "game_example");
	SetTargetFPS(60);
    InitAudioDevice();

	// Φόρτωση εικόνων και ήχων
	jet_img = LoadTextureFromImage(LoadImage("assets/jet.png"));
	warship_img = LoadTextureFromImage(LoadImage("assets/warship.png"));
	heli_img = LoadTextureFromImage(LoadImage("assets/heli.png"));
	game_over_snd = LoadSound("assets/game_over_snd.wav");
    BAckround_snd = LoadSound("assets/Backround_snd.wav");
}

void interface_close() {
	CloseAudioDevice();
	CloseWindow();
}

// Draw game (one frame)
void interface_draw_frame(State state) {
	BeginDrawing();

	// Καθαρισμός, θα τα σχεδιάσουμε όλα από την αρχή
	ClearBackground(RAYWHITE);

	// Σχεδιάζουμε τους χαρακτήρες
	DrawTexture(jet_img, state->character.x, state->character.y, YELLOW);
	DrawTexture(warship_img, state->character.x, state->character.y, RED);
	DrawTexture(warship_img, state->character.x, state->character.y, RED);
    DrawTexture(heli_img, state->character.x, state->character.y, ORANGE);
	DrawTexture(heli_img, state->character.x, state->character.y, ORANGE);
	
	// Σχεδιάζουμε το σκορ και το FPS counter
    DrawText(TextFormat("%04i", state->score), 20, 20, 40, GRAY);
	DrawFPS(SCREEN_WIDTH - 80, 0);

	// Αν το παιχνίδι έχει τελειώσει, σχεδιάζομαι το μήνυμα για να ξαναρχίσει
	if (!state->playing) {
		DrawText(
			"PRESS [ENTER] TO PLAY AGAIN",
			 GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2,
			 GetScreenHeight() / 2 - 50, 20, GRAY
		);
	}
	// Ηχος, αν είμαστε στο frame που συνέβη το game_over
	if(state->game_over)
		PlaySound(game_over_snd);

	
	PlaySound(BAckround_snd);
	EndDrawing();
}