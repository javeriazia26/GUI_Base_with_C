#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static GtkWidget *buttons[3][3];
static GtkWidget *status_label;
static int current_player = 1; // 1 = X, -1 = O
static char board[3][3];
static int moves = 0;

static char check_winner(void) {
    // rows and cols
    for (int i = 0; i < 3; i++) {
        int r = board[i][0] + board[i][1] + board[i][2];
        int c = board[0][i] + board[1][i] + board[2][i];
        if (r == 'X'*3 || c == 'X'*3) return 'X';
        if (r == 'O'*3 || c == 'O'*3) return 'O';
    }
    // diagonals
    int d1 = board[0][0] + board[1][1] + board[2][2];
    int d2 = board[0][2] + board[1][1] + board[2][0];
    if (d1 == 'X'*3 || d2 == 'X'*3) return 'X';
    if (d1 == 'O'*3 || d2 == 'O'*3) return 'O';

    if (moves == 9) return 'D'; // draw
    return 0; // no winner yet
}

static void set_all_sensitive(gboolean s) {
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            gtk_widget_set_sensitive(buttons[r][c], s);
}

static void update_status_turn(void) {
    gtk_label_set_text(GTK_LABEL(status_label),
        (current_player == 1) ? "Turn: X" : "Turn: O");
}

static void on_cell_clicked(GtkButton *btn, gpointer user_data) {
    int idx = GPOINTER_TO_INT(user_data);
    int r = idx / 3;
    int c = idx % 3;

    if (board[r][c] != 0) return; // already filled (shouldn't happen if disabled correctly)

    const char *mark = (current_player == 1) ? "X" : "O";
    gtk_button_set_label(btn, mark);
    gtk_widget_set_sensitive(GTK_WIDGET(btn), FALSE);

    board[r][c] = (current_player == 1) ? 'X' : 'O';
    moves++;

    char w = check_winner();
    if (w == 'X' || w == 'O') {
        char msg[32];
        g_snprintf(msg, sizeof(msg), "Winner: %c 🎉", w);
        gtk_label_set_text(GTK_LABEL(status_label), msg);
        set_all_sensitive(FALSE);
        return;
    } else if (w == 'D') {
        gtk_label_set_text(GTK_LABEL(status_label), "Draw! 🤝");
        set_all_sensitive(FALSE);
        return;
    }

    current_player = -current_player; // switch turn
    update_status_turn();
}

static void on_reset_clicked(GtkButton *btn, gpointer user_data) {
    current_player = 1;
    moves = 0;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            board[r][c] = 0;
            gtk_button_set_label(GTK_BUTTON(buttons[r][c]), "");
            gtk_widget_set_sensitive(buttons[r][c], TRUE);
        }
    }
    update_status_turn();
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Tic Tac Toe (GTK3)");
    gtk_window_set_default_size(GTK_WINDOW(window), 320, 360);
    gtk_container_set_border_width(GTK_CONTAINER(window), 12);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Layout
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    status_label = gtk_label_new("Turn: X");
    gtk_box_pack_start(GTK_BOX(vbox), status_label, FALSE, FALSE, 0);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 6);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 6);
    gtk_box_pack_start(GTK_BOX(vbox), grid, TRUE, TRUE, 0);

    // Buttons 3x3
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            GtkWidget *b = gtk_button_new_with_label("");
            gtk_widget_set_size_request(b, 80, 80);
            gtk_grid_attach(GTK_GRID(grid), b, c, r, 1, 1);
            g_signal_connect(b, "clicked", G_CALLBACK(on_cell_clicked),
                             GINT_TO_POINTER(r * 3 + c));
            buttons[r][c] = b;
            board[r][c] = 0;
        }
    }

    GtkWidget *reset_btn = gtk_button_new_with_label("Reset");
    g_signal_connect(reset_btn, "clicked", G_CALLBACK(on_reset_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), reset_btn, FALSE, FALSE, 0);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
