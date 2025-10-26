# TD04---Liste-Chain-e

🧩 Étape 1 — Créer un compte GitHub

Si ce n’est pas déjà fait :
👉 va sur https://github.com

👉 clique sur Sign up et crée ton compte.
s
🪣 Étape 2 — Installer Git sur les deux ordinateurs
Sur Windows :

Va sur https://git-scm.com/downloads

Télécharge et installe Git.

Pendant l’installation, tu peux laisser toutes les options par défaut.

Vérifie ensuite :

Ouvre le terminal Git Bash ou PowerShell, puis tape :

git --version


Tu dois voir quelque chose comme git version 2.x.x.

🏗️ Étape 3 — Créer un dépôt GitHub

Connecte-toi sur GitHub.

Clique sur le bouton New repository.

Donne un nom à ton projet (ex : traitement-image).

Coche "Add a README" si tu veux.

Clique sur Create repository.

💻 Étape 4 — Envoyer ton code depuis ton portable

Sur ton portable, fais ceci dans le dossier de ton projet :

git init
git add .
git commit -m "Premier commit"
git branch -M main
git remote add origin https://github.com/TON_UTILISATEUR/NOM_DU_REPO.git
git push -u origin main


👉 Remplace TON_UTILISATEUR et NOM_DU_REPO par ton identifiant GitHub et le nom du dépôt.

Tu devras te connecter avec ton compte GitHub (ou ton token personnel si demandé).

🖥️ Étape 5 — Récupérer ton code sur ton PC fixe

Sur ton PC fixe, choisis un dossier où tu veux le projet, puis tape :

git clone https://github.com/TON_UTILISATEUR/NOM_DU_REPO.git


Et voilà 🎉
Tu as maintenant une copie complète du code sur ton PC fixe.

🔄 Étape 6 — Synchroniser les changements
Quand tu modifies ton code sur l’un des deux appareils :
git add .
git commit -m "Description des modifications"
git push

Pour récupérer les nouveaux changements sur l’autre appareil :
git pull
