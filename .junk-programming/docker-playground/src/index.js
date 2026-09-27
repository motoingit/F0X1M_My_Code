import express from 'express';

const app = express();

app.get('/', (req, res) => {
    res.send('Welcome to a terrible Docker tutorial');
});

const port = process.env.PORT || 3000;
app.listen(port, () => {
    console.log(`Unfortunately listening on port http://localhost:${port}`);
});
